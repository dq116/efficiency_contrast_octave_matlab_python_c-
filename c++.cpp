#include<iostream>
#include<time.h>
using namespace std;

const float dt=0.002;
const float densitys[]={300,862,74.2,1.18};
const float cs[]={1377,2100,1726,1005};
const float ks[]={0.082,0.37,0.045,0.028};
float thicknesses[]={0.6, 6, 3.6, 5.5};
const float dxs[]={0.1,0.2,0.6,0.5};
const int n= 1000;
const int r_num=5410;
int num;
float u[n],u_old[n],u_skin[r_num];

float get_dT2(float u1,float u2,float u3,float dx1,float dx2,float c,float density,float k1,float k2)
{
    return ((u1*k1-u2*k1)/dx1+(u3*k2-u2*k2)/dx2)/(0.5*(dx1+dx2)*c*density);
}
float e=0.00000001;
void work(float envir_T,float termi_T,float h1,float h2,float total_time)
{
    int temp=0;
    for(int i=0;i<4;i++)
    {
        temp+=(thicknesses[i]+e)/dxs[i];
    }
    num=temp+2;
    int counter=0;
    u[0]=envir_T;
    u[num-1]=termi_T;
    float c,density,k1,k2,dx1,dx2;
    for(int t=1;t<=int(((total_time+e)*60)/dt);t++)
    {
        if (t%int((1+e)/dt)==0)
        {
            cout<<t/int((1+e)/dt)<<endl;
        }
        int aa=1;
        for(int i2=0;i2<num;i2++)
            u_old[i2]=u[i2];
        for(int i=1;i<num-1;i++)
        {
            int area = (thicknesses[0] + e) / dxs[0];
            for(int j=0;j<4;j++)
            {
                if (i <= area)
                {
                    c = cs[j];
                    k1 = ks[j];
                    density = densitys[j];
                    dx1=dxs[j]*0.001;
                    if (i == area)
                    {
                         k2 = ks[j + 1];
                         dx2=dxs[j+1]*0.001;
                    }
                    else
                     {  
                          k2 = k1;
                          dx2=dx1;
                     }
                    break;
                }  
                else if(j<=2)
                    area += thicknesses[j + 1] / dxs[j+1];
            }
            float dT;
            if (i==1)
            dT=(h1*(u[0]-u_old[1])-k1*(u[1]-u[2])/(dx1))/(density*c*dx1);
            else if (i==num-2 )
            dT=(-h2*(u[num-2]-u[num-1])+k1*(u[num-3]-u[num-2])/dx1)/(density*c*dx1);
            else
            dT= get_dT2(u[i - 1], u[i], u[i + 1], dx1,dx2 , c, density, k1, k2);
    
            u[i] = u[i] + dt * dT;
          
            if (u[i] > u[0] || u[i] < 0)
            {
                cout<<"thk2: "<<thicknesses[1]<<endl;
                cout<<"i: "<<i<<endl;
                cout<<"u[i] "<<u[i]<<endl;
                printf("overflow!!!!!!!!!!!!!!");
                exit(1);
            }

            int palcehodler = 1;
        }

    }
}

int main()
{
    time_t start,stop;
    start = time(NULL);
    work(65,37,106.0,8.2,30);
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));
   
}
