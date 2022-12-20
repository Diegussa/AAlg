set title "N?"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1:100]

set term jpeg
set output "N?100.jpeg"

f(x)=a*x+b
fit f(x) "Prueba.log" using 1:3 via a,b
plot "Prueba.log" using 1:3 lt rgb "blue" title "OB" with l,f(x) title sprintf("f(x)=%.2f N %.2f",a,b),x title "N"

set title "N?"
set xlabel "Tamaño"
set ylabel "AvOB"
set xrange [1:30000]

set term jpeg
set output "N?3K.jpeg"

f(x)=a*x+b
fit f(x) "Prueba3K.log" using 1:3 via a,b
g(x)=c*log(x)/log(2)+d
fit g(x) "Prueba3K.log" using 1:3 via c,d
plot "Prueba3K.log" using 1:3 lt rgb "blue" title "OB" with l,f(x) title sprintf("f(x)=%.2f N+%.2f",a,b),x title "N",g(x) title sprintf("f(x)=%.2f logN %.2f",c,d)