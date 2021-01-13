while :; do
    python3 stats.py
    arduino-cli compile --fqbn arduino:avr:uno sketch
    arduino-cli upload -p "/dev/cu.$(echo $ARDUINO_PORT)" --fqbn arduino:avr:uno sketch
    sleep 60
done