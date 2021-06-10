from sympy import * 
x = Symbol('x') 
f = (x-4)*(x+8) 
f_prime = integrate(f) 
print(f) 
print(f_prime) 
f_prime = lambdify(x, f_prime) 
print(f_prime(1))