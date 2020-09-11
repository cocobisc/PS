import java.io.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
	var n : Int = readLine()!!.toInt()
	val names = Array(n) {readLine()}

	for (name in names) {
		var sum = 0
		for(c in name) {
			if(c == ' ') continue
			sum += (c - 'A').toInt() + 1
		}
		if(sum == 100)
			println("PERFECT LIFE")
		else
			println(sum)
	}
}