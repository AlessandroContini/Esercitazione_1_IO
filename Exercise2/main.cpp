#include <iostream>
#include <fstream>
#include <iomanip>

double function(double x)
{
	x = (x*3 - 7)/4;
	return x;
}


int main()
{
	std::ifstream fstr2("data.txt");
	if(fstr2.fail())
	{
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	
	std::string filename = "result.txt";
	std::ofstream ofs(filename);
	if(ofs.is_open())
	{	
		ofs << "#N mean\n";
		double val;
		double sum = 0.0;
		double mean = 0.0;
		unsigned int i = 0;
		while(fstr2 >> val)
		{
			double x = function(val);
			sum = sum + x;
			mean = sum/(i+1);
			
			ofs << (i+1) << " " << std::scientific << std::setprecision(16) << mean << std::endl;
			i++;
		}
		ofs.close();
		
	}
	
    return 0;
}

