EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PJS:TBS_Crossfire_RF_Receiver A6
U 1 1 5FC9EB0E
P 7800 8850
F 0 "A6" H 7800 9415 50  0000 C CNN
F 1 "TBS_Crossfire_RF_Receiver" H 7800 9324 50  0000 C CNN
F 2 "PJS:TBS_Crossfire_RF_Receiver" H 7800 9300 50  0001 C CNN
F 3 "" H 7800 9300 50  0001 C CNN
	1    7800 8850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4100 3700 3800
Text Label 10200 3350 2    50   ~ 0
SD_DAT2
Text Label 10200 3450 2    50   ~ 0
SD_DAT3
Text Label 10200 3550 2    50   ~ 0
SD_CMD
Text Label 10200 3750 2    50   ~ 0
SD_CLK
Text Label 10200 4050 2    50   ~ 0
SD_DAT1
Text Label 6450 3250 2    50   ~ 0
S1_Link
$Comp
L power:GND #PWR0106
U 1 1 5FF0D821
P 7450 4750
F 0 "#PWR0106" H 7450 4500 50  0001 C CNN
F 1 "GND" V 7455 4622 50  0000 R CNN
F 2 "" H 7450 4750 50  0001 C CNN
F 3 "" H 7450 4750 50  0001 C CNN
	1    7450 4750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5FF0EFCB
P 8300 8550
F 0 "#PWR0108" H 8300 8300 50  0001 C CNN
F 1 "GND" V 8305 8422 50  0000 R CNN
F 2 "" H 8300 8550 50  0001 C CNN
F 3 "" H 8300 8550 50  0001 C CNN
	1    8300 8550
	0    -1   -1   0   
$EndComp
Text Label 6900 4550 0    50   ~ 0
3.3V_Coin
$Comp
L power:GND #PWR0109
U 1 1 5FF2ED77
P 13800 2500
F 0 "#PWR0109" H 13800 2250 50  0001 C CNN
F 1 "GND" V 13805 2372 50  0000 R CNN
F 2 "" H 13800 2500 50  0001 C CNN
F 3 "" H 13800 2500 50  0001 C CNN
	1    13800 2500
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5FF3449F
P 8300 8650
F 0 "#PWR0110" H 8300 8500 50  0001 C CNN
F 1 "+5V" V 8315 8778 50  0000 L CNN
F 2 "" H 8300 8650 50  0001 C CNN
F 3 "" H 8300 8650 50  0001 C CNN
	1    8300 8650
	0    1    1    0   
$EndComp
Text Label 6900 4250 0    50   ~ 0
RF_CH3
Text Label 6900 4350 0    50   ~ 0
RF_CH4
Text Label 6900 4150 0    50   ~ 0
RF_CH2
Text Label 6900 4050 0    50   ~ 0
RF_CH1
Wire Wire Line
	8300 8950 8800 8950
Wire Wire Line
	8300 8750 8800 8750
Text Label 8800 8750 2    50   ~ 0
RF_CH1
Text Label 8800 9050 2    50   ~ 0
RF_CH4
Text Label 8800 8950 2    50   ~ 0
RF_CH3
Wire Wire Line
	8300 9050 8800 9050
Text Label 8800 8850 2    50   ~ 0
RF_CH2
Wire Wire Line
	8300 8850 8800 8850
Text Label 2200 10150 2    50   ~ 0
UAS_DriverOUT1
Text Label 2200 10250 2    50   ~ 0
UAS_DriverOUT2
Text Label 6900 3250 0    50   ~ 0
UAS_DriverIN1
Text Label 6900 3350 0    50   ~ 0
UAS_DriverIN2
Text Label 2200 10750 2    50   ~ 0
Link_DriverOUT1
Text Label 2200 10850 2    50   ~ 0
Link_DriverOUT2
$Comp
L power:+5V #PWR0113
U 1 1 5FF728DB
P 7400 6800
F 0 "#PWR0113" H 7400 6650 50  0001 C CNN
F 1 "+5V" V 7415 6928 50  0000 L CNN
F 2 "" H 7400 6800 50  0001 C CNN
F 3 "" H 7400 6800 50  0001 C CNN
	1    7400 6800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5FF72E32
P 7400 7000
F 0 "#PWR0114" H 7400 6750 50  0001 C CNN
F 1 "GND" V 7405 6872 50  0000 R CNN
F 2 "" H 7400 7000 50  0001 C CNN
F 3 "" H 7400 7000 50  0001 C CNN
	1    7400 7000
	0    1    1    0   
$EndComp
Text Label 6900 5650 0    50   ~ 0
Alt_SCK
Wire Wire Line
	7400 7100 7100 7100
Text Label 7100 7100 0    50   ~ 0
Alt_SCK
Text Label 6900 5550 0    50   ~ 0
Alt_SDI
Wire Wire Line
	8100 7000 8400 7000
Text Label 8400 7000 2    50   ~ 0
Alt_SDI
Text Label 10200 3950 2    50   ~ 0
SD_DAT0
Text Label 10200 3650 2    50   ~ 0
SD_VDD
$Comp
L power:GND #PWR0115
U 1 1 5FF0CBA6
P 7450 3150
F 0 "#PWR0115" H 7450 2900 50  0001 C CNN
F 1 "GND" V 7455 3022 50  0000 R CNN
F 2 "" H 7450 3150 50  0001 C CNN
F 3 "" H 7450 3150 50  0001 C CNN
	1    7450 3150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5FF3345A
P 9650 3850
F 0 "#PWR0116" H 9650 3600 50  0001 C CNN
F 1 "GND" V 9655 3722 50  0000 R CNN
F 2 "" H 9650 3850 50  0001 C CNN
F 3 "" H 9650 3850 50  0001 C CNN
	1    9650 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1600 10150 2200 10150
Wire Wire Line
	1600 10250 2200 10250
Wire Wire Line
	1600 10750 2200 10750
Wire Wire Line
	1600 10850 2200 10850
Wire Wire Line
	6900 5650 7450 5650
Wire Wire Line
	6900 5550 7450 5550
Wire Wire Line
	6900 4550 7450 4550
Wire Wire Line
	6900 4350 7450 4350
Wire Wire Line
	6900 4250 7450 4250
Wire Wire Line
	6900 4150 7450 4150
Wire Wire Line
	6900 4050 7450 4050
Wire Wire Line
	6900 3350 7450 3350
Wire Wire Line
	6900 3250 7450 3250
$Comp
L power:GND #PWR0117
U 1 1 6007335B
P 4900 10850
F 0 "#PWR0117" H 4900 10600 50  0001 C CNN
F 1 "GND" V 4905 10722 50  0000 R CNN
F 2 "" H 4900 10850 50  0001 C CNN
F 3 "" H 4900 10850 50  0001 C CNN
	1    4900 10850
	0    -1   -1   0   
$EndComp
Text Label 3750 10150 2    50   ~ 0
LockA_DriverOUT1
Text Label 3750 10250 2    50   ~ 0
LockA_DriverOUT2
Text Label 3750 10750 2    50   ~ 0
LockB_DriverOUT1
Text Label 3750 10850 2    50   ~ 0
LockB_DriverOUT2
Text Label 6450 4450 2    50   ~ 0
S2_Door
$Comp
L power:GND #PWR0118
U 1 1 5FF0B47F
P 5950 5150
F 0 "#PWR0118" H 5950 4900 50  0001 C CNN
F 1 "GND" V 5955 5022 50  0000 R CNN
F 2 "" H 5950 5150 50  0001 C CNN
F 3 "" H 5950 5150 50  0001 C CNN
	1    5950 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 5FF0ADFD
P 5950 4550
F 0 "#PWR0119" H 5950 4300 50  0001 C CNN
F 1 "GND" V 5955 4422 50  0000 R CNN
F 2 "" H 5950 4550 50  0001 C CNN
F 3 "" H 5950 4550 50  0001 C CNN
	1    5950 4550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5FF0A8DD
P 5950 3950
F 0 "#PWR0120" H 5950 3700 50  0001 C CNN
F 1 "GND" V 5955 3822 50  0000 R CNN
F 2 "" H 5950 3950 50  0001 C CNN
F 3 "" H 5950 3950 50  0001 C CNN
	1    5950 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5950 4450 6450 4450
Wire Wire Line
	6450 3850 5950 3850
Wire Wire Line
	6450 4450 6450 5050
Wire Wire Line
	6450 5050 5950 5050
Wire Wire Line
	6450 3250 6450 3850
$Comp
L PJS:BMP388_Altimeter A5
U 1 1 5FF0C24E
P 7750 6950
F 0 "A5" H 7750 7365 50  0000 C CNN
F 1 "BMP388_Altimeter" H 7750 7274 50  0000 C CNN
F 2 "PJS:BMP388_Altimeter" H 7750 7300 50  0001 C CNN
F 3 "" H 7750 7300 50  0001 C CNN
	1    7750 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 5250 1750 5250
$Comp
L power:GND #PWR0124
U 1 1 5FF72DAA
P 2250 5550
F 0 "#PWR0124" H 2250 5300 50  0001 C CNN
F 1 "GND" H 2255 5377 50  0000 C CNN
F 2 "" H 2250 5550 50  0001 C CNN
F 3 "" H 2250 5550 50  0001 C CNN
	1    2250 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5FF72DB0
P 1750 5550
F 0 "#PWR0125" H 1750 5300 50  0001 C CNN
F 1 "GND" H 1755 5377 50  0000 C CNN
F 2 "" H 1750 5550 50  0001 C CNN
F 3 "" H 1750 5550 50  0001 C CNN
	1    1750 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 5FF72DB6
P 2750 5550
F 0 "#PWR0126" H 2750 5300 50  0001 C CNN
F 1 "GND" H 2755 5377 50  0000 C CNN
F 2 "" H 2750 5550 50  0001 C CNN
F 3 "" H 2750 5550 50  0001 C CNN
	1    2750 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5FF72DBC
P 2650 5050
F 0 "#PWR0127" H 2650 4800 50  0001 C CNN
F 1 "GND" V 2655 4922 50  0000 R CNN
F 2 "" H 2650 5050 50  0001 C CNN
F 3 "" H 2650 5050 50  0001 C CNN
	1    2650 5050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0128
U 1 1 5FF72DC2
P 1850 4950
F 0 "#PWR0128" H 1850 4700 50  0001 C CNN
F 1 "GND" V 1855 4822 50  0000 R CNN
F 2 "" H 1850 4950 50  0001 C CNN
F 3 "" H 1850 4950 50  0001 C CNN
	1    1850 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 5550 3700 5250
$Comp
L power:GND #PWR0129
U 1 1 5FF72DC9
P 3250 5550
F 0 "#PWR0129" H 3250 5300 50  0001 C CNN
F 1 "GND" H 3255 5377 50  0000 C CNN
F 2 "" H 3250 5550 50  0001 C CNN
F 3 "" H 3250 5550 50  0001 C CNN
	1    3250 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0130
U 1 1 5FF72DCF
P 3700 5550
F 0 "#PWR0130" H 3700 5400 50  0001 C CNN
F 1 "+12V" H 3715 5723 50  0000 C CNN
F 2 "" H 3700 5550 50  0001 C CNN
F 3 "" H 3700 5550 50  0001 C CNN
	1    3700 5550
	-1   0    0    1   
$EndComp
Text Label 1150 5150 0    50   ~ 0
Link_DriverIN1
Text Label 1150 5050 0    50   ~ 0
Link_DriverIN2
$Comp
L PJS:R R2
U 1 1 5FF72DDD
P 1750 5400
F 0 "R2" H 1820 5446 50  0000 L CNN
F 1 "30k" H 1820 5355 50  0000 L CNN
F 2 "PJS:0402_Resistor" V 1680 5400 50  0001 C CNN
F 3 "~" H 1750 5400 50  0001 C CNN
	1    1750 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5250 2750 5250
$Comp
L PJS:CP C2
U 1 1 5FF72DE4
P 2750 5400
F 0 "C2" H 2868 5446 50  0000 L CNN
F 1 "47uF" H 2868 5355 50  0000 L CNN
F 2 "PJS:EEE-1CA470SP_Capacitor" H 2788 5250 50  0001 C CNN
F 3 "~" H 2750 5400 50  0001 C CNN
	1    2750 5400
	1    0    0    -1  
$EndComp
Connection ~ 2750 5250
Wire Wire Line
	2750 5250 3250 5250
$Comp
L PJS:C C6
U 1 1 5FF72DEC
P 3250 5400
F 0 "C6" H 3365 5446 50  0000 L CNN
F 1 "0.1uF" H 3365 5355 50  0000 L CNN
F 2 "PJS:CL05B104KO5NNNC_Capacitor" H 3288 5250 50  0001 C CNN
F 3 "~" H 3250 5400 50  0001 C CNN
	1    3250 5400
	1    0    0    -1  
$EndComp
Connection ~ 3250 5250
Wire Wire Line
	3250 5250 3700 5250
$Comp
L PJS:DRV8871_MotorDriver A2
U 1 1 5FF72DF4
P 2250 5100
F 0 "A2" H 2250 5515 50  0000 C CNN
F 1 "DRV8871_MotorDriver" H 2250 5424 50  0000 C CNN
F 2 "PJS:DRV8871_MotorDriver" H 2250 5400 50  0001 C CNN
F 3 "" H 2250 5400 50  0001 C CNN
	1    2250 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 5450 2250 5550
$Comp
L power:+12V #PWR0131
U 1 1 5FF717BB
P 10850 1800
F 0 "#PWR0131" H 10850 1650 50  0001 C CNN
F 1 "+12V" V 10865 1928 50  0000 L CNN
F 2 "" H 10850 1800 50  0001 C CNN
F 3 "" H 10850 1800 50  0001 C CNN
	1    10850 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0132
U 1 1 5FF70E20
P 11550 1750
F 0 "#PWR0132" H 11550 1500 50  0001 C CNN
F 1 "GND" V 11555 1622 50  0000 R CNN
F 2 "" H 11550 1750 50  0001 C CNN
F 3 "" H 11550 1750 50  0001 C CNN
	1    11550 1750
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0133
U 1 1 5FF7064D
P 11550 1650
F 0 "#PWR0133" H 11550 1500 50  0001 C CNN
F 1 "+5V" V 11565 1778 50  0000 L CNN
F 2 "" H 11550 1650 50  0001 C CNN
F 3 "" H 11550 1650 50  0001 C CNN
	1    11550 1650
	0    1    1    0   
$EndComp
Text Label 13300 2300 0    50   ~ 0
3.3V_Coin
Wire Wire Line
	13800 2300 13300 2300
$Comp
L power:GND #PWR0134
U 1 1 5FF2647A
P 13400 1250
F 0 "#PWR0134" H 13400 1000 50  0001 C CNN
F 1 "GND" V 13405 1122 50  0000 R CNN
F 2 "" H 13400 1250 50  0001 C CNN
F 3 "" H 13400 1250 50  0001 C CNN
	1    13400 1250
	0    1    1    0   
$EndComp
$Comp
L PJS:XT60-F_BatteryConnector X3
U 1 1 5FF22EAF
P 13700 1300
F 0 "X3" H 13700 1615 50  0000 C CNN
F 1 "XT60-F_BatteryConnector" H 13700 1524 50  0000 C CNN
F 2 "Connector_AMASS:AMASS_XT60-M_1x02_P7.20mm_Vertical" H 13700 1800 50  0001 C CNN
F 3 "" H 13700 1800 50  0001 C CNN
	1    13700 1300
	-1   0    0    1   
$EndComp
$Comp
L PJS:36-3034-ND_CoinCellHolder BT1
U 1 1 5FCA2E08
P 14050 2400
F 0 "BT1" H 14228 2446 50  0000 L CNN
F 1 "36-3034-ND_CoinCellHolder" H 14228 2355 50  0000 L CNN
F 2 "PJS:36-3034-ND_CoinCellHolder" H 14050 2700 50  0001 C CNN
F 3 "" H 14050 2700 50  0001 C CNN
	1    14050 2400
	1    0    0    -1  
$EndComp
$Comp
L PJS:D24V22F5_VoltageRegulator VR1
U 1 1 5FCA09BF
P 11200 1700
F 0 "VR1" H 11200 2065 50  0000 C CNN
F 1 "D24V22F5_VoltageRegulator" H 11200 1974 50  0000 C CNN
F 2 "PJS:D24V22F5_VoltageRegulator" H 11150 1400 50  0001 C CNN
F 3 "" H 11150 1400 50  0001 C CNN
	1    11200 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5FF33FF2
P 11550 7600
F 0 "#PWR0136" H 11550 7350 50  0001 C CNN
F 1 "GND" V 11555 7472 50  0000 R CNN
F 2 "" H 11550 7600 50  0001 C CNN
F 3 "" H 11550 7600 50  0001 C CNN
	1    11550 7600
	0    1    1    0   
$EndComp
Text Label 10150 8100 0    50   ~ 0
SD_CLK
Text Label 10150 7700 0    50   ~ 0
SD_DAT2
Text Label 10150 7800 0    50   ~ 0
SD_DAT3
Text Label 10150 7900 0    50   ~ 0
SD_CMD
Text Label 10150 8000 0    50   ~ 0
SD_VDD
Text Label 10150 8300 0    50   ~ 0
SD_DAT0
Text Label 10150 8400 0    50   ~ 0
SD_DAT1
Wire Wire Line
	11350 7700 11550 7700
Wire Wire Line
	11350 7800 11550 7800
Wire Wire Line
	11350 7900 11550 7900
Wire Wire Line
	11350 8000 11550 8000
Wire Wire Line
	11350 8100 11550 8100
Wire Wire Line
	11350 8200 11550 8200
Wire Wire Line
	11350 8300 11550 8300
Wire Wire Line
	11350 8400 11550 8400
$Comp
L PJS:MicroSD_Slot XM1
U 1 1 5FC9CA50
P 12450 8000
F 0 "XM1" H 13080 8071 50  0000 L CNN
F 1 "MicroSD_Slot" H 13080 7980 50  0000 L CNN
F 2 "PJS:MicroSD_Slot" H 13600 8300 50  0001 C CNN
F 3 "http://katalog.we-online.de/em/datasheet/693072010801.pdf" H 12250 8000 50  0001 C CNN
	1    12450 8000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 3800 3700 3800
Connection ~ 3250 3800
$Comp
L PJS:C C5
U 1 1 5FFEC8ED
P 3250 3950
F 0 "C5" H 3365 3996 50  0000 L CNN
F 1 "0.1uF" H 3365 3905 50  0000 L CNN
F 2 "PJS:CL05B104KO5NNNC_Capacitor" H 3288 3800 50  0001 C CNN
F 3 "~" H 3250 3950 50  0001 C CNN
	1    3250 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3800 3250 3800
Connection ~ 2750 3800
$Comp
L PJS:CP C1
U 1 1 5FFE9EBB
P 2750 3950
F 0 "C1" H 2868 3996 50  0000 L CNN
F 1 "47uF" H 2868 3905 50  0000 L CNN
F 2 "PJS:EEE-1CA470SP_Capacitor" H 2788 3800 50  0001 C CNN
F 3 "~" H 2750 3950 50  0001 C CNN
	1    2750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 3800 2750 3800
$Comp
L PJS:R R1
U 1 1 5FFE354F
P 1750 3950
F 0 "R1" H 1820 3996 50  0000 L CNN
F 1 "30k" H 1820 3905 50  0000 L CNN
F 2 "PJS:0402_Resistor" V 1680 3950 50  0001 C CNN
F 3 "~" H 1750 3950 50  0001 C CNN
	1    1750 3950
	1    0    0    -1  
$EndComp
Text Label 3350 3700 2    50   ~ 0
UAS_DriverOUT1
Text Label 3350 3500 2    50   ~ 0
UAS_DriverOUT2
Text Label 1150 3600 0    50   ~ 0
UAS_DriverIN2
Text Label 1150 3700 0    50   ~ 0
UAS_DriverIN1
$Comp
L power:+12V #PWR0138
U 1 1 5FF1AF2D
P 3700 4100
F 0 "#PWR0138" H 3700 3950 50  0001 C CNN
F 1 "+12V" H 3715 4273 50  0000 C CNN
F 2 "" H 3700 4100 50  0001 C CNN
F 3 "" H 3700 4100 50  0001 C CNN
	1    3700 4100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5FEC3A3E
P 3250 4100
F 0 "#PWR0107" H 3250 3850 50  0001 C CNN
F 1 "GND" H 3255 3927 50  0000 C CNN
F 2 "" H 3250 4100 50  0001 C CNN
F 3 "" H 3250 4100 50  0001 C CNN
	1    3250 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5FEB1153
P 1850 3500
F 0 "#PWR0105" H 1850 3250 50  0001 C CNN
F 1 "GND" V 1855 3372 50  0000 R CNN
F 2 "" H 1850 3500 50  0001 C CNN
F 3 "" H 1850 3500 50  0001 C CNN
	1    1850 3500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5FEB0BE3
P 2650 3600
F 0 "#PWR0104" H 2650 3350 50  0001 C CNN
F 1 "GND" V 2655 3472 50  0000 R CNN
F 2 "" H 2650 3600 50  0001 C CNN
F 3 "" H 2650 3600 50  0001 C CNN
	1    2650 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5FEB02E0
P 2750 4100
F 0 "#PWR0103" H 2750 3850 50  0001 C CNN
F 1 "GND" H 2755 3927 50  0000 C CNN
F 2 "" H 2750 4100 50  0001 C CNN
F 3 "" H 2750 4100 50  0001 C CNN
	1    2750 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5FEAFBEF
P 1750 4100
F 0 "#PWR0102" H 1750 3850 50  0001 C CNN
F 1 "GND" H 1755 3927 50  0000 C CNN
F 2 "" H 1750 4100 50  0001 C CNN
F 3 "" H 1750 4100 50  0001 C CNN
	1    1750 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5FEAF5B3
P 2250 4100
F 0 "#PWR0101" H 2250 3850 50  0001 C CNN
F 1 "GND" H 2255 3927 50  0000 C CNN
F 2 "" H 2250 4100 50  0001 C CNN
F 3 "" H 2250 4100 50  0001 C CNN
	1    2250 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4000 2250 4100
Wire Wire Line
	1850 3800 1750 3800
Wire Wire Line
	1850 6650 1750 6650
$Comp
L power:GND #PWR0139
U 1 1 5FFC5583
P 2250 6950
F 0 "#PWR0139" H 2250 6700 50  0001 C CNN
F 1 "GND" H 2255 6777 50  0000 C CNN
F 2 "" H 2250 6950 50  0001 C CNN
F 3 "" H 2250 6950 50  0001 C CNN
	1    2250 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0140
U 1 1 5FFC5589
P 1750 6950
F 0 "#PWR0140" H 1750 6700 50  0001 C CNN
F 1 "GND" H 1755 6777 50  0000 C CNN
F 2 "" H 1750 6950 50  0001 C CNN
F 3 "" H 1750 6950 50  0001 C CNN
	1    1750 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0141
U 1 1 5FFC558F
P 2750 6950
F 0 "#PWR0141" H 2750 6700 50  0001 C CNN
F 1 "GND" H 2755 6777 50  0000 C CNN
F 2 "" H 2750 6950 50  0001 C CNN
F 3 "" H 2750 6950 50  0001 C CNN
	1    2750 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0142
U 1 1 5FFC5595
P 2650 6450
F 0 "#PWR0142" H 2650 6200 50  0001 C CNN
F 1 "GND" V 2655 6322 50  0000 R CNN
F 2 "" H 2650 6450 50  0001 C CNN
F 3 "" H 2650 6450 50  0001 C CNN
	1    2650 6450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0143
U 1 1 5FFC559B
P 1850 6350
F 0 "#PWR0143" H 1850 6100 50  0001 C CNN
F 1 "GND" V 1855 6222 50  0000 R CNN
F 2 "" H 1850 6350 50  0001 C CNN
F 3 "" H 1850 6350 50  0001 C CNN
	1    1850 6350
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 6950 3700 6650
$Comp
L power:GND #PWR0144
U 1 1 5FFC55A2
P 3250 6950
F 0 "#PWR0144" H 3250 6700 50  0001 C CNN
F 1 "GND" H 3255 6777 50  0000 C CNN
F 2 "" H 3250 6950 50  0001 C CNN
F 3 "" H 3250 6950 50  0001 C CNN
	1    3250 6950
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0145
U 1 1 5FFC55A8
P 3700 6950
F 0 "#PWR0145" H 3700 6800 50  0001 C CNN
F 1 "+12V" H 3715 7123 50  0000 C CNN
F 2 "" H 3700 6950 50  0001 C CNN
F 3 "" H 3700 6950 50  0001 C CNN
	1    3700 6950
	-1   0    0    1   
$EndComp
Text Label 1150 6550 0    50   ~ 0
LockA_DriverIN1
Text Label 1150 6450 0    50   ~ 0
LockA_DriverIN2
Text Label 3350 6350 2    50   ~ 0
LockA_DriverOUT2
Text Label 3350 6550 2    50   ~ 0
LockA_DriverOUT1
$Comp
L PJS:R R3
U 1 1 5FFC55B6
P 1750 6800
F 0 "R3" H 1820 6846 50  0000 L CNN
F 1 "82k" H 1820 6755 50  0000 L CNN
F 2 "PJS:0402_Resistor" V 1680 6800 50  0001 C CNN
F 3 "~" H 1750 6800 50  0001 C CNN
	1    1750 6800
	1    0    0    -1  
$EndComp
$Comp
L PJS:CP C3
U 1 1 5FFC55BD
P 2750 6800
F 0 "C3" H 2868 6846 50  0000 L CNN
F 1 "47uF" H 2868 6755 50  0000 L CNN
F 2 "PJS:EEE-1CA470SP_Capacitor" H 2788 6650 50  0001 C CNN
F 3 "~" H 2750 6800 50  0001 C CNN
	1    2750 6800
	1    0    0    -1  
$EndComp
Connection ~ 2750 6650
Wire Wire Line
	2750 6650 3250 6650
$Comp
L PJS:C C7
U 1 1 5FFC55C5
P 3250 6800
F 0 "C7" H 3365 6846 50  0000 L CNN
F 1 "0.1uF" H 3365 6755 50  0000 L CNN
F 2 "PJS:CL05B104KO5NNNC_Capacitor" H 3288 6650 50  0001 C CNN
F 3 "~" H 3250 6800 50  0001 C CNN
	1    3250 6800
	1    0    0    -1  
$EndComp
Connection ~ 3250 6650
Wire Wire Line
	3250 6650 3700 6650
$Comp
L PJS:DRV8871_MotorDriver A3
U 1 1 5FFC55CD
P 2250 6500
F 0 "A3" H 2250 6915 50  0000 C CNN
F 1 "DRV8871_MotorDriver" H 2250 6824 50  0000 C CNN
F 2 "PJS:DRV8871_MotorDriver" H 2250 6800 50  0001 C CNN
F 3 "" H 2250 6800 50  0001 C CNN
	1    2250 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 6850 2250 6950
Wire Wire Line
	1850 8050 1750 8050
$Comp
L power:GND #PWR0146
U 1 1 5FFF50D0
P 2250 8350
F 0 "#PWR0146" H 2250 8100 50  0001 C CNN
F 1 "GND" H 2255 8177 50  0000 C CNN
F 2 "" H 2250 8350 50  0001 C CNN
F 3 "" H 2250 8350 50  0001 C CNN
	1    2250 8350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0147
U 1 1 5FFF50D6
P 1750 8350
F 0 "#PWR0147" H 1750 8100 50  0001 C CNN
F 1 "GND" H 1755 8177 50  0000 C CNN
F 2 "" H 1750 8350 50  0001 C CNN
F 3 "" H 1750 8350 50  0001 C CNN
	1    1750 8350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0148
U 1 1 5FFF50DC
P 2750 8350
F 0 "#PWR0148" H 2750 8100 50  0001 C CNN
F 1 "GND" H 2755 8177 50  0000 C CNN
F 2 "" H 2750 8350 50  0001 C CNN
F 3 "" H 2750 8350 50  0001 C CNN
	1    2750 8350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0149
U 1 1 5FFF50E2
P 2650 7850
F 0 "#PWR0149" H 2650 7600 50  0001 C CNN
F 1 "GND" V 2655 7722 50  0000 R CNN
F 2 "" H 2650 7850 50  0001 C CNN
F 3 "" H 2650 7850 50  0001 C CNN
	1    2650 7850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0150
U 1 1 5FFF50E8
P 1850 7750
F 0 "#PWR0150" H 1850 7500 50  0001 C CNN
F 1 "GND" V 1855 7622 50  0000 R CNN
F 2 "" H 1850 7750 50  0001 C CNN
F 3 "" H 1850 7750 50  0001 C CNN
	1    1850 7750
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 8350 3700 8050
$Comp
L power:GND #PWR0151
U 1 1 5FFF50EF
P 3250 8350
F 0 "#PWR0151" H 3250 8100 50  0001 C CNN
F 1 "GND" H 3255 8177 50  0000 C CNN
F 2 "" H 3250 8350 50  0001 C CNN
F 3 "" H 3250 8350 50  0001 C CNN
	1    3250 8350
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0152
U 1 1 5FFF50F5
P 3700 8350
F 0 "#PWR0152" H 3700 8200 50  0001 C CNN
F 1 "+12V" H 3715 8523 50  0000 C CNN
F 2 "" H 3700 8350 50  0001 C CNN
F 3 "" H 3700 8350 50  0001 C CNN
	1    3700 8350
	-1   0    0    1   
$EndComp
Text Label 1150 7950 0    50   ~ 0
LockB_DriverIN1
Text Label 1150 7850 0    50   ~ 0
LockB_DriverIN2
Text Label 3350 7750 2    50   ~ 0
LockB_DriverOUT2
Text Label 3350 7950 2    50   ~ 0
LockB_DriverOUT1
$Comp
L PJS:R R4
U 1 1 5FFF5103
P 1750 8200
F 0 "R4" H 1820 8246 50  0000 L CNN
F 1 "82k" H 1820 8155 50  0000 L CNN
F 2 "PJS:0402_Resistor" V 1680 8200 50  0001 C CNN
F 3 "~" H 1750 8200 50  0001 C CNN
	1    1750 8200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 8050 2750 8050
$Comp
L PJS:CP C4
U 1 1 5FFF510A
P 2750 8200
F 0 "C4" H 2868 8246 50  0000 L CNN
F 1 "47uF" H 2868 8155 50  0000 L CNN
F 2 "PJS:EEE-1CA470SP_Capacitor" H 2788 8050 50  0001 C CNN
F 3 "~" H 2750 8200 50  0001 C CNN
	1    2750 8200
	1    0    0    -1  
$EndComp
Connection ~ 2750 8050
Wire Wire Line
	2750 8050 3250 8050
$Comp
L PJS:C C8
U 1 1 5FFF5112
P 3250 8200
F 0 "C8" H 3365 8246 50  0000 L CNN
F 1 "0.1uF" H 3365 8155 50  0000 L CNN
F 2 "PJS:CL05B104KO5NNNC_Capacitor" H 3288 8050 50  0001 C CNN
F 3 "~" H 3250 8200 50  0001 C CNN
	1    3250 8200
	1    0    0    -1  
$EndComp
Connection ~ 3250 8050
Wire Wire Line
	3250 8050 3700 8050
$Comp
L PJS:DRV8871_MotorDriver A4
U 1 1 5FFF511A
P 2250 7900
F 0 "A4" H 2250 8315 50  0000 C CNN
F 1 "DRV8871_MotorDriver" H 2250 8224 50  0000 C CNN
F 2 "PJS:DRV8871_MotorDriver" H 2250 8200 50  0001 C CNN
F 3 "" H 2250 8200 50  0001 C CNN
	1    2250 7900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 8250 2250 8350
Text Label 3350 5150 2    50   ~ 0
Link_DriverOUT1
Text Label 3350 4950 2    50   ~ 0
Link_DriverOUT2
Wire Wire Line
	2650 3500 3350 3500
Wire Wire Line
	2650 3700 3350 3700
Wire Wire Line
	2650 4950 3350 4950
Wire Wire Line
	2650 5150 3350 5150
Wire Wire Line
	2650 7750 3350 7750
Wire Wire Line
	2650 7950 3350 7950
Wire Wire Line
	1150 3600 1850 3600
Wire Wire Line
	1150 3700 1850 3700
Wire Wire Line
	1150 5050 1850 5050
Wire Wire Line
	1150 5150 1850 5150
Wire Wire Line
	1150 6450 1850 6450
Wire Wire Line
	1150 6550 1850 6550
Wire Wire Line
	1150 7850 1850 7850
Wire Wire Line
	1150 7950 1850 7950
Wire Wire Line
	2650 6350 3350 6350
Wire Wire Line
	2650 6550 3350 6550
Wire Wire Line
	2650 6650 2750 6650
Wire Wire Line
	3100 10850 3750 10850
Wire Wire Line
	3100 10750 3750 10750
Wire Wire Line
	3100 10250 3750 10250
Wire Wire Line
	3100 10150 3750 10150
$Comp
L power:GND #PWR0153
U 1 1 60072D39
P 4900 10250
F 0 "#PWR0153" H 4900 10000 50  0001 C CNN
F 1 "GND" V 4905 10122 50  0000 R CNN
F 2 "" H 4900 10250 50  0001 C CNN
F 3 "" H 4900 10250 50  0001 C CNN
	1    4900 10250
	0    -1   -1   0   
$EndComp
$Comp
L PJS:XT30-F_MotorConnector X2
U 1 1 60017A77
P 4600 10800
F 0 "X2" H 4600 11115 50  0000 C CNN
F 1 "XT30-F_MotorConnector" H 4600 11024 50  0000 C CNN
F 2 "Connector_AMASS:AMASS_XT30U-F_1x02_P5.0mm_Vertical" H 4600 11000 50  0001 C CNN
F 3 "" H 4600 11000 50  0001 C CNN
	1    4600 10800
	1    0    0    -1  
$EndComp
Text Label 5500 10750 2    50   ~ 0
Door_RelayOut2
Text Label 5500 10150 2    50   ~ 0
Door_RelayOut1
$Comp
L PJS:XT30-F_MotorConnector X1
U 1 1 60014C75
P 4600 10200
F 0 "X1" H 4600 10515 50  0000 C CNN
F 1 "XT30-F_MotorConnector" H 4600 10424 50  0000 C CNN
F 2 "Connector_AMASS:AMASS_XT30U-F_1x02_P5.0mm_Vertical" H 4600 10400 50  0001 C CNN
F 3 "" H 4600 10400 50  0001 C CNN
	1    4600 10200
	1    0    0    -1  
$EndComp
$Comp
L PJS:DRV8871_MotorDriver A1
U 1 1 5FF34B84
P 2250 3650
F 0 "A1" H 2250 4065 50  0000 C CNN
F 1 "DRV8871_MotorDriver" H 2250 3974 50  0000 C CNN
F 2 "PJS:DRV8871_MotorDriver" H 2250 3950 50  0001 C CNN
F 3 "" H 2250 3950 50  0001 C CNN
	1    2250 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0156
U 1 1 5FF722D1
P 10100 5550
F 0 "#PWR0156" H 10100 5300 50  0001 C CNN
F 1 "GND" V 10105 5422 50  0000 R CNN
F 2 "" H 10100 5550 50  0001 C CNN
F 3 "" H 10100 5550 50  0001 C CNN
	1    10100 5550
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0157
U 1 1 5FF71D6C
P 10100 5450
F 0 "#PWR0157" H 10100 5300 50  0001 C CNN
F 1 "+5V" V 10115 5578 50  0000 L CNN
F 2 "" H 10100 5450 50  0001 C CNN
F 3 "" H 10100 5450 50  0001 C CNN
	1    10100 5450
	0    1    1    0   
$EndComp
$Comp
L PJS:XT60-F_BatteryConnector X4
U 1 1 5FF20F6C
P 12900 1900
F 0 "X4" H 12900 2215 50  0000 C CNN
F 1 "XT60-F_BatteryConnector" H 12900 2124 50  0000 C CNN
F 2 "Connector_AMASS:AMASS_XT60-M_1x02_P7.20mm_Vertical" H 12900 2400 50  0000 C CNN
F 3 "" H 12900 2400 50  0001 C CNN
	1    12900 1900
	0    -1   -1   0   
$EndComp
$Comp
L power:+12V #PWR0135
U 1 1 5FF3DFBC
P 12850 1350
F 0 "#PWR0135" H 12850 1200 50  0001 C CNN
F 1 "+12V" V 12865 1478 50  0000 L CNN
F 2 "" H 12850 1350 50  0001 C CNN
F 3 "" H 12850 1350 50  0001 C CNN
	1    12850 1350
	0    -1   -1   0   
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J4
U 1 1 5FF15321
P 2900 10200
F 0 "J4" H 2900 10515 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 2900 10424 50  0000 C CNN
F 2 "PJS:SM02B-PASS-TBT_Connector" H 2900 11000 50  0001 C CNN
F 3 "" H 2900 11000 50  0001 C CNN
	1    2900 10200
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J2
U 1 1 5FF1608E
P 1400 10200
F 0 "J2" H 1400 10515 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 1400 10424 50  0000 C CNN
F 2 "PJS:SM02B-PASS-TBT_Connector" H 1400 11000 50  0001 C CNN
F 3 "" H 1400 11000 50  0001 C CNN
	1    1400 10200
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J3
U 1 1 5FF16A59
P 1400 10800
F 0 "J3" H 1400 11115 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 1400 11024 50  0000 C CNN
F 2 "PJS:SM02B-PASS-TBT_Connector" H 1400 11600 50  0001 C CNN
F 3 "" H 1400 11600 50  0001 C CNN
	1    1400 10800
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J5
U 1 1 5FF1768B
P 2900 10800
F 0 "J5" H 2900 11115 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 2900 11024 50  0000 C CNN
F 2 "PJS:SM02B-PASS-TBT_Connector" H 2900 11600 50  0001 C CNN
F 3 "" H 2900 11600 50  0001 C CNN
	1    2900 10800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3250 6450 3250
$Comp
L power:GND #PWR0121
U 1 1 5FF0A3C2
P 5950 3350
F 0 "#PWR0121" H 5950 3100 50  0001 C CNN
F 1 "GND" V 5955 3222 50  0000 R CNN
F 2 "" H 5950 3350 50  0001 C CNN
F 3 "" H 5950 3350 50  0001 C CNN
	1    5950 3350
	0    -1   -1   0   
$EndComp
Text Label 6450 5650 2    50   ~ 0
S3_UAS
Wire Wire Line
	5950 5650 6450 5650
$Comp
L power:GND #PWR0123
U 1 1 5FF19762
P 5950 5750
F 0 "#PWR0123" H 5950 5500 50  0001 C CNN
F 1 "GND" V 5955 5622 50  0000 R CNN
F 2 "" H 5950 5750 50  0001 C CNN
F 3 "" H 5950 5750 50  0001 C CNN
	1    5950 5750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7450 4450 6900 4450
Wire Wire Line
	10100 5550 9650 5550
Wire Wire Line
	9650 5450 10100 5450
Wire Wire Line
	9650 4050 10200 4050
Wire Wire Line
	9650 3950 10200 3950
Wire Wire Line
	9650 3750 10200 3750
Wire Wire Line
	9650 3650 10200 3650
Wire Wire Line
	9650 3550 10200 3550
Wire Wire Line
	9650 3450 10200 3450
Wire Wire Line
	9650 3350 10200 3350
Text Label 10200 5850 2    50   ~ 0
S2_Door
Wire Wire Line
	10200 5850 9650 5850
Wire Wire Line
	6900 5850 7450 5850
Text Label 6900 5850 0    50   ~ 0
S1_Link
Text Label 6900 4450 0    50   ~ 0
Relay_Signal
Wire Wire Line
	6900 3450 7450 3450
Text Label 6900 3450 0    50   ~ 0
Link_DriverIN1
Wire Wire Line
	7450 3550 6900 3550
Text Label 6900 3550 0    50   ~ 0
Link_DriverIN2
Wire Wire Line
	7450 3650 6900 3650
Text Label 6900 3650 0    50   ~ 0
LockA_DriverIN1
Wire Wire Line
	7450 3750 6900 3750
Text Label 6900 3750 0    50   ~ 0
LockA_DriverIN2
Wire Wire Line
	7450 3850 6900 3850
Text Label 6900 3850 0    50   ~ 0
LockB_DriverIN1
Wire Wire Line
	7450 3950 6900 3950
Text Label 6900 3950 0    50   ~ 0
LockB_DriverIN2
$Comp
L PJS:G2R-2-DC5_Relay K1
U 1 1 5FCA000B
P 2200 1350
F 0 "K1" H 2200 2115 50  0000 C CNN
F 1 "G2R-2-DC5_Relay" H 2200 2024 50  0000 C CNN
F 2 "PJS:G2R-2-DC5_Relay" H 2200 2050 50  0001 C CNN
F 3 "" H 2200 2050 50  0001 C CNN
	1    2200 1350
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0111
U 1 1 5FF56403
P 1900 1450
F 0 "#PWR0111" H 1900 1300 50  0001 C CNN
F 1 "+12V" V 1915 1578 50  0000 L CNN
F 2 "" H 1900 1450 50  0001 C CNN
F 3 "" H 1900 1450 50  0001 C CNN
	1    1900 1450
	0    -1   -1   0   
$EndComp
$Comp
L power:+12V #PWR0112
U 1 1 5FF568D5
P 2500 1450
F 0 "#PWR0112" H 2500 1300 50  0001 C CNN
F 1 "+12V" V 2515 1578 50  0000 L CNN
F 2 "" H 2500 1450 50  0001 C CNN
F 3 "" H 2500 1450 50  0001 C CNN
	1    2500 1450
	0    1    1    0   
$EndComp
Text Label 1300 1350 0    50   ~ 0
Door_RelayOut1
Wire Wire Line
	1900 1350 1300 1350
$Comp
L power:GND #PWR0122
U 1 1 5FF68CB5
P 3250 1850
F 0 "#PWR0122" H 3250 1600 50  0001 C CNN
F 1 "GND" V 3255 1722 50  0000 R CNN
F 2 "" H 3250 1850 50  0001 C CNN
F 3 "" H 3250 1850 50  0001 C CNN
	1    3250 1850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3100 1350 2500 1350
Text Label 3100 1350 2    50   ~ 0
Door_RelayOut2
Wire Wire Line
	3050 2450 3050 2950
$Comp
L PJS:R R5
U 1 1 5FFF9163
P 3050 2300
F 0 "R5" H 3120 2346 50  0000 L CNN
F 1 "2k" H 3120 2255 50  0000 L CNN
F 2 "PJS:ERA-6AEB202V" V 2980 2300 50  0001 C CNN
F 3 "~" H 3050 2300 50  0001 C CNN
	1    3050 2300
	1    0    0    -1  
$EndComp
Text Label 3050 2950 1    50   ~ 0
Relay_Signal
$Comp
L PJS:MMBT222A_Transistor Q1
U 1 1 5FEF3CA0
P 3050 1900
F 0 "Q1" V 3235 1900 50  0000 C CNN
F 1 "MMBT222A_Transistor" V 3326 1900 50  0000 C CNN
F 2 "PJS:MMBT2222A_Transistor" H 3050 2500 50  0001 C CNN
F 3 "" H 3050 2500 50  0001 C CNN
	1    3050 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 1850 2500 1850
Wire Wire Line
	2850 1850 2600 1850
Connection ~ 2600 1850
$Comp
L PJS:Teensy4.0 U2
U 1 1 5FFF6DFD
P 8550 4500
F 0 "U2" H 8550 6115 50  0000 C CNN
F 1 "Teensy4.0" H 8550 6024 50  0000 C CNN
F 2 "PJS:Teensy4.0" H 8150 4700 50  0001 C CNN
F 3 "" H 8150 4700 50  0001 C CNN
	1    8550 4500
	1    0    0    -1  
$EndComp
Text Label 10200 5750 2    50   ~ 0
S3_UAS
Wire Wire Line
	9650 5750 10200 5750
Wire Wire Line
	8300 9150 8800 9150
Text Label 6800 9150 0    50   ~ 0
RF_CH6
Text Label 8800 9150 2    50   ~ 0
RF_CH5
Wire Wire Line
	7300 9150 6800 9150
Wire Wire Line
	7450 5050 6950 5050
Text Label 6950 5050 0    50   ~ 0
RF_CH5
Wire Wire Line
	7450 5150 6950 5150
Text Label 6950 5150 0    50   ~ 0
RF_CH6
Wire Wire Line
	10550 8400 10150 8400
Wire Wire Line
	10550 8300 10150 8300
Wire Wire Line
	10150 8000 10550 8000
Wire Wire Line
	10550 7900 10150 7900
Wire Wire Line
	10550 7800 10150 7800
Wire Wire Line
	10550 7700 10150 7700
Wire Wire Line
	10550 8100 10150 8100
$Comp
L PJS:HFW8R-1STE1H1LF_FFC J1
U 1 1 5FC972AB
P 10950 8050
F 0 "J1" H 10950 8665 50  0000 C CNN
F 1 "HFW8R-1STE1H1LF_FFC" H 10950 8574 50  0000 C CNN
F 2 "PJS:HFW8R-1STE1H1LF_FFC" H 11000 7500 50  0001 C CNN
F 3 "" H 11000 7500 50  0001 C CNN
	1    10950 8050
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5FF32F5C
P 10550 8200
F 0 "#PWR0137" H 10550 7950 50  0001 C CNN
F 1 "GND" V 10555 8072 50  0000 R CNN
F 2 "" H 10550 8200 50  0001 C CNN
F 3 "" H 10550 8200 50  0001 C CNN
	1    10550 8200
	0    1    1    0   
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J6
U 1 1 5FF34C1C
P 5750 3300
F 0 "J6" H 5833 3575 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 5833 3484 50  0000 C CNN
F 2 "" H 5750 4100 50  0001 C CNN
F 3 "" H 5750 4100 50  0001 C CNN
	1    5750 3300
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J7
U 1 1 5FF35CEB
P 5750 3900
F 0 "J7" H 5833 4175 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 5833 4084 50  0000 C CNN
F 2 "" H 5750 4700 50  0001 C CNN
F 3 "" H 5750 4700 50  0001 C CNN
	1    5750 3900
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J8
U 1 1 5FF3C0BA
P 5750 4500
F 0 "J8" H 5833 4775 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 5833 4684 50  0000 C CNN
F 2 "" H 5750 5300 50  0001 C CNN
F 3 "" H 5750 5300 50  0001 C CNN
	1    5750 4500
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J9
U 1 1 5FF423A5
P 5750 5100
F 0 "J9" H 5833 5375 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 5833 5284 50  0000 C CNN
F 2 "" H 5750 5900 50  0001 C CNN
F 3 "" H 5750 5900 50  0001 C CNN
	1    5750 5100
	1    0    0    -1  
$EndComp
$Comp
L PJS:SM02B-PASS-TBT_Connector J10
U 1 1 5FF486F6
P 5750 5700
F 0 "J10" H 5833 5975 50  0000 C CNN
F 1 "SM02B-PASS-TBT_Connector" H 5833 5884 50  0000 C CNN
F 2 "" H 5750 6500 50  0001 C CNN
F 3 "" H 5750 6500 50  0001 C CNN
	1    5750 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	13400 1350 12950 1350
Wire Wire Line
	5650 10150 5650 10750
Wire Wire Line
	4900 10750 5650 10750
Wire Wire Line
	4900 10150 5650 10150
Wire Wire Line
	12950 1600 12950 1350
Wire Wire Line
	12850 1600 12850 1350
Wire Wire Line
	12850 1350 12850 1100
Wire Wire Line
	12850 1100 10100 1100
Wire Wire Line
	10100 1100 10100 2100
Wire Wire Line
	10100 2100 10850 2100
Wire Wire Line
	10850 2100 10850 1800
Connection ~ 12850 1350
Connection ~ 10850 1800
Wire Wire Line
	2600 1850 2600 2450
Wire Wire Line
	1800 1850 1800 2750
Wire Wire Line
	1800 2750 2600 2750
Wire Wire Line
	1800 1850 1900 1850
$Comp
L power:+5V #PWR0154
U 1 1 60053597
P 1800 2750
F 0 "#PWR0154" H 1800 2600 50  0001 C CNN
F 1 "+5V" V 1815 2878 50  0000 L CNN
F 2 "" H 1800 2750 50  0001 C CNN
F 3 "" H 1800 2750 50  0001 C CNN
	1    1800 2750
	0    -1   -1   0   
$EndComp
Connection ~ 1800 2750
$Comp
L PJS:1SS351-TB-E_Diode D1
U 1 1 600E996D
P 2600 2600
F 0 "D1" V 2646 2520 50  0000 R CNN
F 1 "1SS351-TB-E_Diode" V 2555 2520 50  0000 R CNN
F 2 "" H 2600 2600 50  0001 C CNN
F 3 "" H 2600 2600 50  0001 C CNN
	1    2600 2600
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
