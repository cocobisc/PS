import com.sun.xml.internal.fastinfoset.util.StringArray
import java.io.*
import kotlin.time.seconds

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val words = Array(n) {readLine()}
    var ma = sortedMapOf<String, Int>()
    for(s in words) {
        var k = ma[s] ?: 0
        ma[s] = k + 1
    }
    var m = ma.toList().sortedWith(compareByDescending { it.second }).toMap()

    print("${m.keys.toList()[0]}")
}