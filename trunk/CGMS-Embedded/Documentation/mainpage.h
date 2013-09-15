/****************************************************************************/
/*! \mainpage
**  \details    Este documento contiene la informacion relacionada con el dise�o
** de un medidor de insulina. Basicamente este dispositivo interpreta los resultados
 que regresa un sensor CGMS. El sensor regresa una determinada cantidad de corriente
 del orden de los nanoamperes, la cu�l ser� medida e interpretada por un microcontrolador
 PIC 18F4550. Una vez obtenidos los resultados de las diferentes mediciones ser�n mostradas
 en un display LCD incluido en dispositivo. Se incluye la opci�n para comunicarse con una
 PC por medio de comunicaci�n serial. Los resultados son mostrados por la Glucommeter-GUI.
 
******************************************************************************
**  \par        Authors:
				- Carlos Enrique D�az Guerrero
				- 206425577
				- Universidad de Guadalajara
				- Centro Universiario de Ciencias Exactas e Ingenier�as
				- Ingenier�a en Comunicaciones y electr�nica
******************************************************************************
**  \version    32 Carlos D�az
**              - Creaci�n del Archivo de Documentaci�n.
*************************************************************** <P><HR SIZE=1>
**                
******************************************************************************
**  \section    s_def  Definiciones y Abreviaciones
**  <TABLE>
		<TR><TD>CGMS	<TD>Sensor de medici�n cont�nua de glucosa
		<TR><TD>CNT 	<TD>Voltaje medido desde la se�al CNT del sensor CGMS
		<TR><TD>E2P		<TD>EEPROM
		<TR><TD>EEPROM	<TD>Memoria Porgramble de solo lectura borrable electronicamente.
		<TR><TD>GND 	<TD>Referencia Negativa (Tierra)
		<TR><TD>GUI 	<TD>Interfaz Gr�fica para Usuario
		<TR><TD>HW	 	<TD>Hardware.
		<TR><TD>ISIG 	<TD>Corriente que circula a travez del cable de WRK
		<TR><TD>LCD 	<TD>Pantalla de Cristal L�quido
		<TR><TD>OPAM 	<TD>Amplificador Operacional
		<TR><TD>PC	 	<TD>Computadora Personal.
		<TR><TD>PCB	 	<TD>Tarjeta de Circuito Impreso.
		<TR><TD>REF 	<TD>Voltaje medido desde la se�al REF del sensor CGMS
		<TR><TD>SW	 	<TD>Software.
		<TR><TD>VCC 	<TD>Voltaje Positivo en la parte de medici�n. (3.30Volts)
		<TR><TD>VCTR 	<TD>Voltaje medido entre los cables WRK y REF
		<TR><TD>VGND 	<TD>Nivel de referencia negativa virtual. Debe ser equivalente a VCC/2
		<TR><TD>WRK 	<TD>Voltaje medido desde la se�al WRK del sensor CGMS
******************************************************************************
**  \section    s_ref  Referencias
		- Hoja de datos PIC18F4550
		- Hoja de datos LMC6042
		- Hoja de datos LM7805
		- Hoja de datos LM375z

******************************************************************************
**  \section    s_tgt  Objetivos y Alcances:
**  \par        Alcances:
				- En esta versi�n el dispositivo es capaz de hacer mediciones 
				del sensor y mostrarlos en un display LCD o por medio de la GUI en
				la PC. 
				- Las PCB del Hardware no est� disponible a�n pero el Hw esta
				disponible en un protoboard.
				- Respecto a la comuniciaci�n con la PC solamente est� implementado
				el modo de monitoreo.
				
**
**  \par        Objetivos:
				- El m�dulo deber� de ser capaz de almacenar los datos medidos en una EEPROM.
				En una primera etapa los datos ser�n almacenados en la EEPROM interna del
				microcontrolador. Para etapas mas avanzadas la informaci�n deber� ser guardada 
				en una E2P externa.
				- El Hw deber� estar en una sola PCB, para finalidades de integraci�n.
*/


/****************************************************************************/
/*! \page       SWA	Descripci�n de la Arquitectura del Software
******************************************************************************
**  \section    Des Descripci�n:
**              La arquitectura del software esta basada en los modelos de capaz.
**				Se estan manejando principalmente las siguientes capas:
**				- \subpage drv "Drivers"
**				- \subpage int "Interface"
**				- \subpage app "Applicaci�n"
**				- \subpage sch "Scheduler"
**	\n			Actualmente s�lo se han definido las capas de Drivers, Applicaci�n y Sheduler.
**				La capa de Interface no es indisplensable, pero se implementar� en versiones
**				siguientes.
******************************************************************************
**  \section    s_int Interacci�n:
**  \dot        digraph G
**              {
             		node 	[ fontname=Helvetica, fontsize=10, shape=component, height=.1 ];
		            edge 	[ fontname=Helvetica, fontsize=10 ];
		            mod 	[ label="Glucometro", height=.5, style="bold,filled" ];
		            appl 	[ label="Aplicacion", height=.5, style="bold,filled" ];
		            int 	[ label="Interface", height=.5, style="bold,filled" ];
		            sch 	[ label="Scheduler", height=.5, style="bold,filled" ];
					drv 	[ label="Driver", height=.5, style="bold,filled" ];
              		appl -> mod;
					int -> mod;
					sch -> mod;
					drv -> mod;         

**              }
**  \enddot




 
/****************************************************************************/
/*!
\page       M_Hw  Descripci�n del Hardware.
******************************************************************************
\page       M_ser Conmunicaci�n Serial
******************************************************************************
*/











/****************************************************************************/
/*! \page       drv Drivers
**  \details    Esta secci�n incluye la descripci�n de los Drivers implementados 
				para este dispositivo
				\image html UdeG.jpg
******************************************************************************
**  \page       int Interface
**  \details    Esta secci�n incluye la descripci�n de las Interfaces implementados 
				para este dispositivo
******************************************************************************
**  \page       app Applicaci�n
**  \details    Esta secci�n incluye la descripci�n de la capa de applicaci�n y cada 
				uno de los m�dulos que la componen.
******************************************************************************
**  \page       sch Scheduler
**  \details    Esta secci�n incluye una peque�a expliaci�n del funcionamiento del scheduler.
*/

