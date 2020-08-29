import time
densitys=[300,862,74.2,1.18]
cs=[1377,2100,1726,1005]
ks=[0.082,0.37,0.045,0.028]
thicknesses=[0.6, 6, 3.6, 5]
dt=0.002
dx=0.1
total_thickness = sum(thicknesses)
u = [37.0] * (int(total_thickness / dx) + 2)
num=len(u)
e=0.00000001
def get_dT2(u1,u2,u3,dx,c,density,k1,k2):
    p=(k1/(c*density))
    return p*(u1*k1+u3*k2-u2*k1-u2*k2)/(dx*dx)
def work(envir_T, skin_T, total_time):
    u[0] = envir_T
    u[len(u) - 1] = skin_T
    c = density =k1 = k2 = 0.0
    for t in range(int((total_time+e) * 60 / dt)):
        if (t % 500) == 0:
            print(t / 500)
        for i in range(1, num- 1):
            area = int((thicknesses[0] + e) / dx)
            for j in range(4):
                if (i <= area):
                    c = cs[j]
                    k1 = ks[j]
                    density = densitys[j]
                    if (i == area):
                        k2 = ks[j + 1]
                    else:
                        k2 = k1
                    break
                elif j<2:
                    area += thicknesses[j + 1] / dx

            dT = get_dT2(u[i - 1], u[i], u[i + 1], dx * 0.001, c, density, k1, k2)

            u[i] = u[i] + dt * dT
            if u[i] > u[0] or u[i] < 0:
                print("overflow!!!")
                exit()
            palcehodler = 1

if __name__ == "__main__":
    work(75.0,37.0,2)
    print("time used:" + str(time.perf_counter()))
