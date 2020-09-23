import java.util.*

fun main() {
    val (n,m,k) = readLine()!!.split(" ").map{it.toInt()}
    val arr = Array(n) { Array(m) {0} }
    val check = Array(n) { Array(m) {0} }
    val dx = arrayOf(1, -1, 0, 0)
    val dy = arrayOf(0, 0, 1, -1)
    var ans = 0

    repeat(k) {
        val (y, x) = readLine()!!.split(" ").map{it.toInt()}
        arr[y - 1][x - 1] = 1
    }

    fun bfs(xx : Int, yy : Int) {
        val q = LinkedList<Pair<Int, Int>>()
        check[yy][xx] = 1
        q.add(Pair(xx, yy))
        var cnt = 0

        while(!q.isEmpty()) {
            val (x, y) = q.peek()
            q.poll()
            cnt++
            for (i in 0..3) {
                val (nx, ny) = arrayOf(x + dx[i], y + dy[i])
                if(nx in 0..m-1 && ny in 0..n-1 && check[ny][nx] == 0 && arr[ny][nx] == 1) {
                    q.add(Pair(nx, ny))
                    check[ny][nx] = 1
                }
            }
        }
        ans = maxOf(ans, cnt)
    }
    for(i in 0..n - 1)
        for(j in 0..m - 1)
            if(check[i][j] == 0 && arr[i][j] == 1) bfs(j, i)

    print(ans)
}