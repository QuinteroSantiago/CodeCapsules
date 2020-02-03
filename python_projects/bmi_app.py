def bmi_app():
	h = input('How tall are you?(cm)')
	w = input('How much do you weigh?(kg)')
	bmi = int(w)/((int(h)/100)**2)
	print('Your bmi is {}'.format(round(bmi, 2)))
	if bmi < 18.5:
		print('You\'re underweight. Try to gain weight')
	if bmi >= 18.5 and bmi <= 24:
		print('You\'re in a healthy weight range')
	else:
		print('You\'re overweight. Try to lose weight')

bmi_app()

input('Press ENTER to exit')