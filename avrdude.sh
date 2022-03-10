# avrdude.sh 
TOOLBOXDIR='./qmk_toolbox/'
MODECMD='/mnt/c/Windows/System32/mode.com'

COMPORT1=$(${MODECMD} | grep -o 'COM[0-9]*')
COMPORT2=""
while [ "$COMPORT2" = "" ];do
  sleep 1
  printf "."
  COMPORT2=$(${MODECMD} | grep -v '${COMPORT1}' | grep -o 'COM[0-9]*')
done
echo $COMPORT2
${TOOLBOXDIR}windows/QMK\ Toolbox/Resources/avrdude.exe -C ${TOOLBOXDIR}common/avrdude.conf -c avr109 -p m32u4 -P ${COMPORT2} -U flash:w:$*