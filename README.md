# Bird house

Casa de pájaros conectada a una placa Arduino y Raspberry pi.

## Componentes utilizados
* Arduino
* Raspberry pi 4
* Cámara de raspberry 8M
* Sensor de ultrasonido
* Led y resistencias
* Fotoresistencia

Al arduino va conectado el sensor de ultrasonido, que se utiliza para detectar cuando un pájaro entra o sale de la casa. Una vez que se detecta que el pájaro a entrado a la casa se activa un led interior para mejora la calidad de la imagen tomada y se envía una señal por el puerto serial para poder activar la cámara.

# Siguientes mejoras
* Dashboard front-end para controlar los dispositivos y ver en tiempo real la cámara de la raspberry.
* Crear un aviso para cuando se detecte que ha entrado un pájaro me envie un Telegram. 
