fun main() {
	var a = readLine()!!.toInt()
	
	val checkMinsu = a@ { x: Int ->
		val s : String = x.toString()
		for(c in s)
			if(c != '4' && c != '7') return@a false
		true
	}
	val getMinsu = b@ { k: Int ->
		for(i in k downTo 4) 
			if(checkMinsu(i)) return@b i
		4
	}
	print(getMinsu(a))
}