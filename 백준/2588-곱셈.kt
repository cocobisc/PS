import java.io.*

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n1 : Int
    val n2 : String

    n1 = br.readLine().toInt()
    n2 = br.readLine()
    for (i in n2.length - 1 downTo 0)
        println((n2[i] - '0').toInt() * n1)
    println(n1 * n2.toInt())
}