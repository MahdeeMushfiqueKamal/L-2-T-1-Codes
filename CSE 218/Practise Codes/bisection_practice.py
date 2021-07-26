import math

f = lambda x : x**3 - 0.165*x**2 + 3.993e-4 


def bisection(xl, xr, err_tol, max_ittr):
    # initial values check
    if(f(xl) * f(xr) >= 0):
        print("Invalid values.")
        return
    xm_old = xl+ xr # random value
    for i in range(max_ittr):
        xm = 0.5*(xl + xr)
        epx_err = abs((xm - xm_old)/xm)
        xm_old = xm
        
        if f(xm) ==0 or epx_err <= err_tol:
            break
        elif f(xm) * f(xl) > 0:
            xl = xm
        else:
            xr = xm
    return xm


print(bisection(0, 0.11, 0.000000005,20000))
