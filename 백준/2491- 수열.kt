import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val arr = readLine()!!.split(" ").map { it.toInt() }.toList()
    var ans = 0

    fun go(arr: List<Int>) {
        val st = Stack<Int>()
        arr.forEach {
            if (st.empty() || st.peek() <= it) st.push(it)
            else {
                st.clear()
                st.push(it)
            }
            ans = maxOf(ans, st.size)
        }
    }
    go(arr)
    go(arr.reversed())

    print(ans)
}