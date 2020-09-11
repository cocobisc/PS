import java.io.*

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val str = br.readLine()
    val arr = IntArray(26){0}

    for(c in str) {
        val idx = if(c > 'Z') c - 'a' else c - 'A'
        arr[idx]++
    }

    var max = 0
    for(n in arr)
        if (max < n) max = n
    var ans : Int? = null
    for(i in 0 until 26) {
        if (arr[i] == max) {
            if(ans != null) {
                print("?")
                return
            }
            ans = i
        }
    }
    print("${(ans!! + 'A'.toInt()).toChar()}")
}