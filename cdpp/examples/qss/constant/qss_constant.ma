[top]
components : integrator@QSS1
out : signalOut
in : signalIn
link : signalIn in@integrator
link : out@integrator signalOut


[integrator]
x0 : 0
dQRel : 0
dQMin : 0.1
invert : 0