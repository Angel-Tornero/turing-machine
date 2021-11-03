# Máquina de Turing 1
# Reconoce el lenguaje  L = { a^nb^m | m < n, n > 0 }
q0 q1 q2 q3 q4 q5
a b x y
a b x y .
q0
.
q5
q0 a q1 x R
q0 y q3 y R
q1 a q1 a R
q1 y q1 y R
q1 b q2 y L
q2 y q2 y L
q2 a q2 a L
q2 x q0 x R
q3 y q3 y R
q3 b q4 y R
q4 b q4 y R
q4 . q5 . L 