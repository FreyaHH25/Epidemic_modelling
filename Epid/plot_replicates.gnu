set xlabel 'Dage'
set ylabel 'Antal individer'
set title 'Stochastic SIR Model - 2 Replicates (Input 1)'
set grid
set key outside top center
set key maxcols 5
set style line 1 lc rgb '#8000FF00' lt 1 lw 1
set style line 2 lc rgb '#80FFA500' lt 1 lw 1
set style line 3 lc rgb '#80FF0000' lt 1 lw 1
set style line 4 lc rgb '#80800080' lt 1 lw 1
set style line 5 lc rgb '#800000FF' lt 1 lw 1
plot 'stochastic_replicates.txt' index 0 using 1:2 with lines ls 1 title 'S (Input 1)', \
'stochastic_replicates.txt' index 0 using 1:3 with lines ls 3 title 'I (Input 1)', \
'stochastic_replicates.txt' index 0 using 1:4 with lines ls 5 title 'R (Input 1)', \
'stochastic_replicates.txt' index 1 using 1:2 with lines ls 1 notitle, \
'stochastic_replicates.txt' index 1 using 1:3 with lines ls 3 notitle, \
'stochastic_replicates.txt' index 1 using 1:4 with lines ls 5 notitle
pause -1 'Tast enter for at lukke'
