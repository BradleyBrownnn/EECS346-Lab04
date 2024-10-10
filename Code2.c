#include <stdio.h>
#include <stdlib.h>

float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's freezing, stay warm!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and avoid the heat.\n");
    }
}

void convert_temperature(float temp, int from_scale, int to_scale) {
    float converted_temp;

    // Celsius to other scales
    if (from_scale == 1 && to_scale == 2) {
        converted_temp = celsius_to_fahrenheit(temp);
        printf("Converted temperature: %.2fÂ°F\n", converted_temp);
    } else if (from_scale == 1 && to_scale == 3) {
        converted_temp = celsius_to_kelvin(temp);
        printf("Converted temperature: %.2fK\n", converted_temp);
    }
    // Fahrenheit to other scales
    else if (from_scale == 2 && to_scale == 1) {
        converted_temp = fahrenheit_to_celsius(temp);
        printf("Converted temperature: %.2fÂ°C\n", converted_temp);
    } else if (from_scale == 2 && to_scale == 3) {
        converted_temp = fahrenheit_to_kelvin(temp);
        printf("Converted temperature: %.2fK\n", converted_temp);
    }
    // Kelvin to other scales
    else if (from_scale == 3 && to_scale == 1) {
        converted_temp = kelvin_to_celsius(temp);
        printf("Converted temperature: %.2fÂ°C\n", converted_temp);
    } else if (from_scale == 3 && to_scale == 2) {
        converted_temp = kelvin_to_fahrenheit(temp);
        printf("Converted temperature: %.2fÂ°F\n", converted_temp);
    } else {
        printf("Invalid conversion choice.\n");
        return;
    }

    // Categorize temperature after conversion
    if (to_scale == 1) { // Use Celsius scale for categorization
        categorize_temperature(converted_temp);
    } else if (to_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temp));
    } else {
        categorize_temperature(kelvin_to_celsius(converted_temp));
    }
}

int main() {
    float temp;
    int from_scale, to_scale;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &from_scale);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &to_scale);

    // Input validation for invalid scales or temperature values
    if ((from_scale < 1 || from_scale > 3) || (to_scale < 1 || to_scale > 3)) {
        printf("Invalid scale choice.\n");
        return 1;
    }

    if (from_scale == 3 && temp < 0) {
        printf("Invalid temperature value. Kelvin cannot be negative.\n");
        return 1;
    }

    if (from_scale == to_scale) {
        printf("No conversion needed. The temperature remains the same.\n");
    } else {
        convert_temperature(temp, from_scale, to_scale);
    }

    return 0;
}
