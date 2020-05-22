'''
Quick CFM Calculator
Cat Litter volume is 6ft^3
'''
# how long does the exhaust fan need to be on (t)

time = 0
cfm = int(input("Fan CFM Rating: "))

litter_vol = 6
air_change = 8


def cat_litter_exhaust(cfm):
    total_air_change = litter_vol * air_change
    return total_air_change/cfm


time_fan_on = cat_litter_exhaust(cfm)

print("Fan should run for {} mins".format(time_fan_on))
