#include <iostream>
#include <string>
using namespace std;
class device
{
private:
    int device_mass;
    int device_volume;
    int device_surface;
    int shape1;
    int shape2;
    string *parts;
    float *mass;
    float *volume;
    float *surface;
public:
    device()
    {
        device_mass = 0;
        device_volume = 0;
        device_surface =0; 
        shape1 = 0;

        parts = new string[0];
        mass = new float[0];
        volume = new float[0];
        surface = new float[0];
    }
    void add_new_shape()
    {
        shape1 += 1;
        string *newparts = new string[shape1];
        float *newmass = new float[shape1];
        float *newvolume = new float[shape1];
        float *newsurface= new float[shape1];
        for (int i = 0; i < shape1 - 1; i++)
        {
            newparts[i] = parts[i];
            newmass[i] = mass[i];
            newvolume[i] = volume[i];
            newsurface[i] = surface[i];
        }
        cout << "enter new shape name: ";
        cin >> newparts[shape1 - 1];
        cout << "enter new shape mass: ";
        cin >> newmass[shape1 - 1];
        cout << "enter new shape volume: ";
        cin >> newvolume[shape1 - 1];
        cout << "enter new shape surface: ";
        cin >> newsurface[shape1 - 1];
        delete[] parts;
        parts = newparts;
        delete[] mass;
        mass = newmass;
        delete[] volume;
        volume = newvolume;
        delete[] surface;
        surface = newsurface;
    }
    void showdevice()
    {
        cout << "this device contains of this shapes: " << endl;
        for (int i = 0; i < shape1; i++)
        {
            cout << i + 1 << ": " << parts[i] << " with the mass of: " << mass[i] << " with the volume of: " << volume[i] 
                 << " with the surface of: "<< surface[i]<<endl;
        }
    }
    int calculate_mass()
    {
        for (int i = 0; i < shape1; i++)
        {
            device_mass += mass[i];
        }
        cout << "device mass = " << device_mass << endl;
        return device_mass;
    }
    int calculate_volume()
    {
        for (int i = 0; i < shape1; i++)
        {
            device_volume += volume[i];
        }
        cout << "device volume = " << device_volume << endl;
        return device_volume;
    }
        int calculate_surface()
    {
        for (int i = 0; i < shape1; i++)
        {
            device_surface += surface[i];
        }
        cout << "device surface = " << device_surface<< endl;
        return device_surface;
    }
    int density(){
        cout<<"enter 0 for density of device, or the number of the shape: "<<endl;
        for (int i = 0; i < shape1; i++)
        {
            device_volume += volume[i];
        }
         for (int i = 0; i < shape1; i++)
        {
            device_mass += mass[i];
        }
        int j;
        cin>>j;
        if(j>shape1 || j<0)
            cout<<"invalid index"<<endl;
        else if(j==0)
            {cout<< " the density of the device is: "<< (device_mass/device_volume)<<endl;
            return (device_mass/device_volume);}
        else
            {cout<<" the density of the "<< j << " item is: "<<(mass[j-1]/volume[j-1])<<endl;
            return (mass[j-1]/volume[j-1]);}
    }
};

int main()
{
    device a;
    a.add_new_shape();
    a.add_new_shape();
    a.add_new_shape();
    a.calculate_mass();
    a.calculate_volume();
    a.density();
    a.density();
    a.density();
    a.density();
    a.density();
    a.showdevice();
}
