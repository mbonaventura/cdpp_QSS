[top]
components : qssX@QSS1 qssY@QSS1
out  : signalOut
in : signalIn
link : out@qssY in@qssX
link : out@qssX in@qssY
link : out@qssX signalOut
link : out@qssY signalOut

[qssX]
x0 : 4.5
dQRel : 0.001
dQMin : 0.0001
invert : 0

[qssY]
x0 : 0.5
dQRel : 0.001
dQMin : 0.0001
invert : 1
