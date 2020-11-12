    fun main() {
     
        val T = readLine()!!.toInt()
        for (t in 0 until T) {
            val vwv = readLine()!!
     
            if(vwv.length == 1 && vwv[0] == 'v') {
                println("0")
                continue
            }
     
            var is_w = 0
            for(n in 0 until vwv.length) {
                if (vwv[n] == 'w') {
                    is_w = 1
                }
            }
     
            if (is_w == 0) {
                var res = Math.floor(vwv.length.toDouble()/2.0).toInt()
                println("$res")
                continue
            }
     
            
            var prev = 0
            var res = 0
            var first_w = 0
            var markers = IntArray(vwv.length+1) {0}
            for(n in 0 until vwv.length) {
                var s = vwv[n]
                if (s == 'w') {
                    var d:Int?
                    if(first_w == 0) {
                        d = n - prev
                        prev = n
                        first_w = 1
                    } else {
                        d = n - prev - 1
                        prev = n
                    }
                    
                    markers[n] = d
                    res = res + 1
                }
            }
     
            if(vwv[vwv.length-1] == 'v') {
                markers[vwv.length] = vwv.length - prev - 1
            }
            
            // println("Inter: $res")
            
            for(n in 0 until vwv.length+1) {
                if(markers[n] <= 1 ) {
                    continue
                }
     
                res = res + Math.floor(markers[n].toDouble()/2.0).toInt()
            }
     
            // println(markers.contentToString())
            println("$res")
        }
    }