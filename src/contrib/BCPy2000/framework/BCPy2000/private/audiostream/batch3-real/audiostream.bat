#! ../prog/BCI2000Shell
@cls & ..\prog\BCI2000Shell %0 %* #! && exit /b 0 || exit /b 1

########################################################################################

set environment BATCHDIR ${CD}
set environment PARMSDIR ${canonical path ${BATCHDIR}/../parms}
set environment PYWD     ${canonical path ${BATCHDIR}/../python}
set environment PYLOGDIR ${canonical path ${BATCHDIR}/../log}

set environment SUBJECT TestSubject
if [ ${Arg1} ]; set environment SUBJECT ${Arg1}; end

set environment CONDITION 002
if [ ${Arg2} ]; set environment CONDITION ${Arg2}; end

set environment MODE CALIB
if [ ${Arg3} ]; set environment MODE ${Arg3}; end

set environment SRC gUSBampSource
if [ ${Arg4} ]; set environment SRC ${Arg4}; end

set environment MONTAGE D
if [ ${Arg5} ]; set environment MONTAGE ${Arg5}; end

########################################################################################

set environment TIMINGFLAG --EvaluateTiming=1 # TODO: really this shouldn't be necessary
if [ ${SRC} == SignalGenerator ]; set environment TIMINGFLAG --EvaluateTiming=0 ; end

change directory ${BCI2000LAUNCHDIR}
if [ ${get system state} != Idle ]; shutdown system; wait for Idle; end
show window; set title ${Extract file base ${Arg0}}
startup system

#start executable ${SRC}                 AUTOSTART 127.0.0.1 --SignalSourceIP=127.0.0.1     ${TIMINGFLAG} # TODO: logger flags...
#start executable PythonSignalProcessing AUTOSTART 127.0.0.1 --SignalProcessingIP=127.0.0.1 --PythonSigWD=${PYWD} --PythonSigClassFile=Streaming.py       --PythonSigLog=${PYLOGDIR}/###-sig.txt --PythonSigShell=1
#start executable PythonApplication      AUTOSTART 127.0.0.1 --ApplicationIP=127.0.0.1      --PythonAppWD=${PYWD} --PythonAppClassFile=TrialStructure.py  --PythonAppLog=${PYLOGDIR}/###-app.txt --PythonAppShell=1

wait for connected

########################################################################################

if [ ${MONTAGE} == D ]
	load parameterfile ${PARMSDIR}/gUSBamp-Cap8-SMR-REVERSED-WIRING.prm
elseif [ ${MONTAGE} == 16 ]
	load parameterfile ${PARMSDIR}/gUSBamp-Cap16.prm
else
	error unrecognized montage ${MONTAGE}
end

load parameterfile ${PARMSDIR}/realbase.prm 
load parameterfile ${PARMSDIR}/condition${CONDITION}.prm

if [ ${MODE} == FREE ]
	load parameterfile ${PARMSDIR}/realfree.prm 
elseif [ ${MODE} != CALIB ]
	error unrecognized mode ${MODE}
end

if [ ${SRC} == Emotiv ]
	load parameterfile ${PARMSDIR}/epoc.prm
end

########################################################################################

#TODO: find the right data directory
#TODO: use the data directory, subject name, mode and session to find the data directory that will be used; then load weights from there 
set parameter SubjectName    ${SUBJECT}${MODE}
set parameter SubjectSession ${CONDITION}

########################################################################################

warn ${BATCHDIR}
warn ${get parameter DataDirectory}
