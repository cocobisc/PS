import java.util.Scanner

fun main() {
	val sc = Scanner(System.`in`)
	val A = IntArray(10)
	var cnt1 = 0
	var cnt2 = 0
	val getWinner = {x : Int, y : Int -> 
		when {
			x > y -> 0
			x < y -> 1
			else -> 2
		}
	}

	for(i in 0 until 10) 
		A[i] = sc.nextInt()
	for(i in 0 until 10) {
		val t = sc.nextInt()
		val type = getWinner(A[i], t) 

		if (type == 1) cnt2++
		else if (type == 0) cnt1++
	}
	when {
		cnt1 < cnt2 -> print("B")
		cnt1 > cnt2 -> print("A")
		else -> print("D")
	}
}