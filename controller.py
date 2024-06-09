import serial

ser = serial.Serial('COM13',1600,timeout=None)

def motor(total):
    if total==0:    #stop moving
        ser.write(b'0')

    elif total==1:  #go right
        ser.write(b'1')

    elif total==2:  #go left
        ser.write(b'2')

    elif total==3:  #stop moving
        ser.write(b'0')     #IF BACKWARD CHANGE TO 3

    elif total==4:  #stop moving
        ser.write(b'0')

    elif total==5:  #go forward
        ser.write(b'5')

