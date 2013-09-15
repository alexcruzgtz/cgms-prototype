/****************************************************************************/
/*! \mainpage
**  \details    Este documento contiene la informacion relacionada con el diseño
** de un medidor de insulina. Basicamente este dispositivo interpreta los resultados
 que regresa un sensor CGMS. El sensor regresa una determinada cantidad de corriente
 del orden de los nanoamperes, la cuál será medida e interpretada por un microcontrolador
 PIC 18F4550. Una vez obtenidos los resultados de las diferentes mediciones serán mostradas
 en un display LCD incluido en dispositivo. Se incluye la opción para comunicarse con una
 PC por medio de comunicación serial. Los resultados son mostrados por la Glucommeter-GUI.
 
******************************************************************************
**  \par        Authors:
				- Carlos Enrique Díaz Guerrero
				- 206425577
				- Universidad de Guadalajara
				- Centro Universiario de Ciencias Exactas e Ingenierías
				- Ingeniería en Comunicaciones y electrónica
******************************************************************************
**  \version    32 Carlos Díaz
**              - Creación del Archivo de Documentación.
*************************************************************** <P><HR SIZE=1>
**                
******************************************************************************
**  \section    s_def  Definiciones y Abreviaciones
**  <TABLE>
		<TR><TD>CGMS	<TD>Sensor de medición contínua de glucosa
		<TR><TD>CNT 	<TD>Voltaje medido desde la señal CNT del sensor CGMS
		<TR><TD>E2P		<TD>EEPROM
		<TR><TD>EEPROM	<TD>Memoria Porgramble de solo lectura borrable electronicamente.
		<TR><TD>GND 	<TD>Referencia Negativa (Tierra)
		<TR><TD>GUI 	<TD>Interfaz Gráfica para Usuario
		<TR><TD>HW	 	<TD>Hardware.
		<TR><TD>ISIG 	<TD>Corriente que circula a travez del cable de WRK
		<TR><TD>LCD 	<TD>Pantalla de Cristal Líquido
		<TR><TD>OPAM 	<TD>Amplificador Operacional
		<TR><TD>PC	 	<TD>Computadora Personal.
		<TR><TD>PCB	 	<TD>Tarjeta de Circuito Impreso.
		<TR><TD>REF 	<TD>Voltaje medido desde la señal REF del sensor CGMS
		<TR><TD>SW	 	<TD>Software.
		<TR><TD>VCC 	<TD>Voltaje Positivo en la parte de medición. (3.30Volts)
		<TR><TD>VCTR 	<TD>Voltaje medido entre los cables WRK y REF
		<TR><TD>VGND 	<TD>Nivel de referencia negativa virtual. Debe ser equivalente a VCC/2
		<TR><TD>WRK 	<TD>Voltaje medido desde la señal WRK del sensor CGMS
******************************************************************************
**  \section    s_ref  Referencias
		- Hoja de datos PIC18F4550
		- Hoja de datos LMC6042
		- Hoja de datos LM7805
		- Hoja de datos LM375z

******************************************************************************
**  \section    s_tgt  Objetivos y Alcances:
**  \par        Alcances:
				- En esta versión el dispositivo es capaz de hacer mediciones 
				del sensor y mostrarlos en un display LCD o por medio de la GUI en
				la PC. 
				- Las PCB del Hardware no está disponible aún pero el Hw esta
				disponible en un protoboard.
				- Respecto a la comuniciación con la PC solamente está implementado
				el modo de monitoreo.
				
**
**  \par        Objetivos:
				- El módulo deberá de ser capaz de almacenar los datos medidos en una EEPROM.
				En una primera etapa los datos serán almacenados en la EEPROM interna del
				microcontrolador. Para etapas mas avanzadas la información deberá ser guardada 
				en una E2P externa.
				- El Hw deberá estar en una sola PCB, para finalidades de integración.
*/


/****************************************************************************/
/*! \page       SWA	Descripción de la Arquitectura del Software
******************************************************************************
**  \section    Des Descripción:
**              La arquitectura del software esta basada en los modelos de capaz.
**				Se estan manejando principalmente las siguientes capas:
**				- \subpage drv "Drivers"
**				- \subpage int "Interface"
**				- \subpage app "Applicación"
**				- \subpage sch "Scheduler"
**	\n			Actualmente sólo se han definido las capas de Drivers, Applicación y Sheduler.
**				La capa de Interface no es indisplensable, pero se implementará en versiones
**				siguientes.
******************************************************************************
**  \section    s_int Interacción:
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
\page       M_Hw  Descripción del Hardware.
******************************************************************************
\page       M_ser Conmunicación Serial
******************************************************************************
*/











/****************************************************************************/
/*! \page       drv Drivers
**  \details    Esta sección incluye la descripción de los Drivers implementados 
				para este dispositivo
				\image html UdeG.jpg
******************************************************************************
**  \page       int Interface
**  \details    Esta sección incluye la descripción de las Interfaces implementados 
				para este dispositivo
******************************************************************************
**  \page       app Applicación
**  \details    Esta sección incluye la descripción de la capa de applicación y cada 
				uno de los módulos que la componen.
******************************************************************************
**  \page       sch Scheduler
**  \details    Esta sección incluye una pequeña expliación del funcionamiento del scheduler.
*/

