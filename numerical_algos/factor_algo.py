#!/usr/bin/env python3

number = int(raw_input("Enter a number whose factors need to be found: "))
factors = []
stop = int(number**(1/2.0))
current = 3

while number%2 == 0:
	factors.append(2)
	number = int(number/2)
while (current<=stop):
	while number%current == 0:
		factors.append(current)
		number = int(number/current)

	current += 2

if number != 1:
	factors.append(number)

print("Factors for the given number are: ")
for item in factors:
	print(item)

