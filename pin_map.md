# PIN Map
LPC4088 board PIN configuration:

Pin | Port | Component | Func
---|---|---|---
PIN1 | GND | Multiple | GND
PIN44 | VOUT | Multiple | 5V VOUT
PIN15 | PORT0_23 | Speed Sensor | T3_CAP_0
PIN34 | PORT0_4 | Speed Sensor | T2_CAP_0 (Not used)
PIN30 | PORT1_2 | Motor Controller | PWM0_1(ENB)
PIN29 | PORT1_3 | Motor Controller | PWM0_2(ENA)
-PIN11 | PORT0_9 | Motor Controller | GPIO - IN2
PIN12 | PORT0_8 | Motor Controller | GPIO - IN1
PIN13 | PORT0_7 | Motor Controller | GPIO - IN4
-PIN16 | PORT0_24 | Motor Controller | GPIO - IN3
PIN5 | PORT1_24 | LED | Front Right LED
PIN6 | PORT1_23 | LED | Front Left LED
PIN7 | PORT1_20 | LED | Back Right LED
PIN8 | PORT0_21 | LED | Back Left LED
--||||
PIN11 | PORT0_9 | Ultrasonic Sensor Trigger | T2_MAT_3 |
PIN16 | PORT0_24 | Ultrasonic Sensor Echo | T3_CAP_1 |