
set title "Distintos casos de MergeSort en profundidad"
set xlabel "Tamaño"
set ylabel "Prof"
set xrange [0:20]
set yrange [0: 10]
set term jpeg
set output "MergeSortProf10.jpeg"
plot "MergeSortProf10.txt" using 1:3 lt rgb "blue" title "MergeSort AvProf" with l,"MergeSortProf10.txt" using 1:4 lt rgb "violet" title "MergeSort MaxProf" with l, "MergeSortProf10.txt" using 1:5 lt rgb "green" title "MergeSort MinProf" with l,log(x)/log(2)+1 title "log(N)+1" lt rgb "red", x title "N" lt rgb "black"

set title "Distintos casos de QuickSort con median en profundidad"
set xlabel "Tamaño"
set ylabel "Prof"
set xrange [0:20]
set yrange [0: 10]
set term jpeg
set output "QuickSortProf10.jpeg"
plot "QuickSortProf10.txt" using 1:3 lt rgb "blue" title "QuickSort AvProf" with l,"QuickSortProf10.txt" using 1:4 lt rgb "violet" title "QuickSort MaxProf" with l, "QuickSortProf10.txt" using 1:5 lt rgb "green" title "QuickSort MinProf" with l,log(x)/log(2)+1 title "log(N)+1" lt rgb "red"
set title "Distintos casos de QuickSort con median stat en profundidad"
set xlabel "Tamaño"
set ylabel "Prof"
set xrange [0:20]
set yrange [0: 10]
set term jpeg
set output "QuickSortProfmedian_stat10.jpeg"
plot "QuickSortProf_median_stat10.txt" using 1:3 lt rgb "blue" title "QuickSort AvProf" with l,"QuickSortProf_median_stat10.txt" using 1:4 lt rgb "violet" title "QuickSort MaxProf" with l, "QuickSortProf_median_stat10.txt" using 1:5 lt rgb "green" title "QuickSort MinProf" with l,log(x)/log(2)+1 title "log(N)+1" lt rgb "red"
set title "Comparacion casos de QuickSort con median y QuickSort con median stat en profundidad"
set xlabel "Tamaño"
set ylabel "Prof"
set xrange [0:20]
set yrange [0: 10]
set term jpeg
set output "CompQuickSortProf10.jpeg"
plot "QuickSortProf10.txt" using 1:3 lt rgb "blue" title "QuickSort median AvProf" with l,"QuickSortProf_median_stat10.txt" using 1:3 lt rgb "violet" title "QuickSort median stat AvProf" with l, log(x)/log(2) title "log(N)" lt rgb "red"