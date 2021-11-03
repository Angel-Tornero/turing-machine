# Máquina de Turing 2
# MT que reciba como parámetro una cadena binaria y separe los ceros y los unos,
# colocando en la cinta primero los ceros y después los unos dejando un espacio en
# blanco entre ellos:
q0 q1 q2 q3 q4 q5 q6 q7 q8 q9 q10
0 1 x y z
0 1 x y z .
q0
.
q10
q0 0 q0 0 L
q0 1 q0 1 L
q0 x q0 x L
q0 y q2 y R
q0 . q2 y R
q1 0 q1 0 L
q1 1 q1 1 L
q1 x q1 x L
q1 z q1 z L
q1 y q2 y R
q2 0 q3 x R
q2 1 q2 1 R
q2 x q2 x R
q2 z q5 z L
q3 0 q3 0 R
q3 1 q3 1 R
q3 x q3 x R
q3 z q3 z R
q3 . q4 z R
q3 z q4 z R
q4 . q1 0 L
q4 0 q4 0 R
q5 0 q5 0 L
q5 z q5 z L
q5 1 q5 1 L
q5 x q5 x L
q5 . q5 . L
q5 y q6 y R
q6 x q6 x R
q6 1 q7 x R
q6 z q9 . L
q7 0 q7 0 R
q7 1 q7 1 R
q7 x q7 x R
q7 z q7 z R
q7 . q8 . R
q8 1 q8 1 R
q8 . q5 1 L
q9 0 q9 0 L
q9 x q9 . L
q9 z q9 . L
q9 y q10 . R