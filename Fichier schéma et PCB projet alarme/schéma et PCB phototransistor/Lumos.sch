EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
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
L power:+5V #PWR0101
U 1 1 5EBD5E4D
P 4300 3300
F 0 "#PWR0101" H 4300 3150 50  0001 C CNN
F 1 "+5V" H 4315 3473 50  0000 C CNN
F 2 "" H 4300 3300 50  0001 C CNN
F 3 "" H 4300 3300 50  0001 C CNN
	1    4300 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5EBD66FC
P 7050 4650
F 0 "#PWR0102" H 7050 4400 50  0001 C CNN
F 1 "GND" H 7055 4477 50  0000 C CNN
F 2 "" H 7050 4650 50  0001 C CNN
F 3 "" H 7050 4650 50  0001 C CNN
	1    7050 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5EBD96C7
P 6150 4250
F 0 "C1" V 5898 4250 50  0000 C CNN
F 1 "10uF" V 5989 4250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 6188 4100 50  0001 C CNN
F 3 "~" H 6150 4250 50  0001 C CNN
	1    6150 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	4300 3300 4300 3400
Wire Wire Line
	4300 3400 4500 3400
Wire Wire Line
	5650 3500 6000 3500
Text GLabel 5500 4650 0    50   Output ~ 0
OutA4
Wire Wire Line
	5650 4250 5800 4250
Wire Wire Line
	4700 3400 4700 3450
$Comp
L Device:Q_Photo_NPN Q1
U 1 1 5EBDB5FC
P 4600 3650
F 0 "Q1" H 4790 3696 50  0000 L CNN
F 1 "Q_Photo_NPN" H 4790 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4800 3750 50  0001 C CNN
F 3 "~" H 4600 3650 50  0001 C CNN
	1    4600 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3500 5650 3850
Wire Wire Line
	7050 4250 6300 4250
Wire Wire Line
	7050 3500 7050 4250
Connection ~ 7050 4250
Wire Wire Line
	7050 4250 7050 4650
Wire Wire Line
	5800 4250 5800 4650
Wire Wire Line
	5800 4650 5500 4650
Connection ~ 5800 4250
Wire Wire Line
	5800 4250 6000 4250
Wire Wire Line
	4700 3850 5650 3850
Connection ~ 5650 3850
Wire Wire Line
	5650 3850 5650 4250
$Comp
L Connector:Conn_01x03_Female J1
U 1 1 5EBE678B
P 6350 2550
F 0 "J1" H 6378 2576 50  0000 L CNN
F 1 "Conn_01x03_Female" H 6378 2485 50  0000 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Horizontal" H 6350 2550 50  0001 C CNN
F 3 "~" H 6350 2550 50  0001 C CNN
	1    6350 2550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5EBE693A
P 5850 2300
F 0 "#PWR0103" H 5850 2150 50  0001 C CNN
F 1 "+5V" H 5865 2473 50  0000 C CNN
F 2 "" H 5850 2300 50  0001 C CNN
F 3 "" H 5850 2300 50  0001 C CNN
	1    5850 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5EBE8528
P 5850 2750
F 0 "#PWR0104" H 5850 2500 50  0001 C CNN
F 1 "GND" H 5855 2577 50  0000 C CNN
F 2 "" H 5850 2750 50  0001 C CNN
F 3 "" H 5850 2750 50  0001 C CNN
	1    5850 2750
	1    0    0    -1  
$EndComp
Text GLabel 5700 2550 0    50   Input ~ 0
OutA4
Wire Wire Line
	5850 2300 5850 2450
Wire Wire Line
	5850 2450 6150 2450
Wire Wire Line
	6150 2550 5700 2550
Wire Wire Line
	6150 2650 5850 2650
Wire Wire Line
	5850 2650 5850 2750
$Comp
L Device:C C2
U 1 1 5EC2CBCC
P 4900 3250
F 0 "C2" V 4648 3250 50  0000 C CNN
F 1 "10uF" V 4739 3250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 4938 3100 50  0001 C CNN
F 3 "~" H 4900 3250 50  0001 C CNN
	1    4900 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5EC2D31E
P 5300 3250
F 0 "#PWR0105" H 5300 3000 50  0001 C CNN
F 1 "GND" H 5305 3077 50  0000 C CNN
F 2 "" H 5300 3250 50  0001 C CNN
F 3 "" H 5300 3250 50  0001 C CNN
	1    5300 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5300 3250 5050 3250
Wire Wire Line
	4750 3250 4500 3250
Wire Wire Line
	4500 3250 4500 3400
Connection ~ 4500 3400
Wire Wire Line
	4500 3400 4700 3400
$Comp
L Device:R R1
U 1 1 5EBD7E90
P 6150 3500
F 0 "R1" V 5943 3500 50  0000 C CNN
F 1 "100k" V 6034 3500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6080 3500 50  0001 C CNN
F 3 "~" H 6150 3500 50  0001 C CNN
	1    6150 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 3500 7050 3500
$EndSCHEMATC
