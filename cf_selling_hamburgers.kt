    fun main() {
     
        val T = readLine()!!.toInt()
        for (t in 0 until T) {
            val N = readLine()!!.toLong()
            val a_vec = readLine()!!.split(" ").map { it.toLong() }
            val s_a_vec = a_vec.sorted()
            // println("$s_a_vec")
     
            var res: Long = 0
            for(n in 0 until N) {
                var new_res: Long = s_a_vec[n.toInt()]*(N - n.toLong())
                if(new_res > res) {
                    res = new_res
                }
            }
     
            println("$res")
     
        }
    }