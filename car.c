
#include "Car.h"


void car_init(car_t* self,
			  const char* brand,
			  const char* model,
			  const char* color,
			  unsigned int year_of_launch,
			  transmisson_t transmission)
{
	self->brand = brand;
	self->model = model;
	self->color = color;
	self->year_of_launch = year_of_launch;
	self->transmisson = transmission;

	self->color_change = car_change_color;
	self->transmission_change = car_change_transmission;
	self->print = car_print;

	return;
}

void car_clear(car_t* self)
{
	self->brand = 0;
	self->color = 0;
	self->model = 0;
	self->transmisson = 0;
	self->year_of_launch = 0;

	return;
}

car_t* car_new(const char* brand,
			   const char* model,
			   const char* color,
			   unsigned int year_of_launch,
			   transmisson_t transmission)
{
	car_t* self = (car_t*)malloc(sizeof(car_t));
	if (!self) return 0;
	car_init(self, brand, model, color, year_of_launch, transmission);
	return self;
}

void car_delete(car_t** self)
{
	free(*self);
	*self = 0;
	return;
}

void car_print(const car_t* self, FILE* ostream)
{
	if (!ostream) ostream = stdout;
	fprintf(ostream, "------------------------------------------------------------\n");
	fprintf(ostream,"Brand:\t\t %s\n", self->brand);
	fprintf(ostream,"Model:\t\t %s\n", self->model);
	fprintf(ostream,"Color:\t\t %s\n", self->color);
	fprintf(ostream,"Year:\t\t %u\n", self->year_of_launch);
	
	if (self->transmisson == TRANSMISSON_AUTOMATIC)
	{
		fprintf(ostream, "Transmission\t Automatic\n");
	}
	else
	{
		fprintf(ostream, "Transmission\t Manual\n");
	}
	fprintf(ostream, "------------------------------------------------------------\n");
	
	
	return;
}

void car_change_color(car_t* self, const char* new_color)
{
	self->color = new_color;

	return;
}

void car_change_transmission(car_t* self, transmisson_t new_transmission)
{
	self->transmisson = new_transmission;
	return;
}

int car_text_read(const char* filepath)
{
	FILE* input_stream = fopen(filepath, "r");

	if (!input_stream)
	{
		fprintf(stdout, "%s not found", filepath);
		return 1;
	}
	else
	{
		char s[100] = { '\0' };
		while (fgets(s, sizeof(s), input_stream))
		{
			fprintf(stdout, "%s", s);
		}

		fclose(input_stream);
		return 0;
	}

}
