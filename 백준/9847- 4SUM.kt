import java.util.*

lateinit var arr: Array<IntArray>
var a = mutableListOf<Int>()

fun go(idx: Int, sum: Int, st: Stack<Int>): Boolean {
    if (idx == 4) {
        if (sum == 0) return true
        return false
    }
    for (j in 0..a[idx] - 1) {
        st.add(arr[idx][j])
        if (go(idx + 1, sum + arr[idx][j], st))
            return true
        st.pop()
    }

    return false
}

fun main() = with(Scanner(System.`in`)) {
    
    a = mutableListOf(4) { nextInt() }
    val siz = a.max()!!
    arr = Array(4, { IntArray(siz) })
    val st = Stack<Int>()

    for (i in 0..3) {
        for (j in 0..a[i] - 1) {
            arr[i][j] = nextInt()
        }
    }
    go(0, 0, st)
    st.forEach { print("$it ") }
}