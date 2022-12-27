#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	TRANSMISSON_AUTOMATIC,
	TRANSMISSON_MANUAL

} transmisson_t;

typedef struct car
{
	const char* brand;
	const char* model;
	const char* color;
	unsigned int year_of_launch;
	transmisson_t transmisson;
	void (*color_change)(struct car* self, const char* new_color);
	void (*transmission_change)(struct car* self, transmisson_t new_transmission);
	void (*print)(const struct car* self, FILE* ostream);

} car_t;

//Gör så att self pekar på rätt sak i struckten
void car_init(car_t* self, 
			  const char* brand,
			  const char* model, 
			  const char* color, 
			  unsigned int year_of_launch,
			  transmisson_t transmission);

//Tar bort all text
void car_clear(car_t* self);

//Lägger till en ny bil
car_t* car_new(const char* brand,
	           const char* model,
	           const char* color,
	           unsigned int year_of_launch,
	           transmisson_t transmission);

//Tar bort en bil
void car_delete(car_t** self);

//Skriver ut bilen
void car_print(const car_t* self, FILE* ostream);

//Du kan ändra den nuvarande färg till en ny färg
void car_change_color(car_t* self, const char* color);

//Ändra mellan manuell och automat
void car_change_transmission(car_t* self, transmisson_t new_transmission);

//Läser text dockumenten ut i terminalen
int car_text_read(const char* filepath);