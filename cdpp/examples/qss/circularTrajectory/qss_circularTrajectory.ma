[top]
components : qssX@QSS1 qssY@QSS1
out : signalOut
link : out@qssY in@qssX
link : out@qssX in@qssY
link : out@qssX signalOut

[qssX]
x0 : 0.5
dQRel : 0.1
dQMin : 0.1
invert : 0

[qssY]
x0 : 0
dQRel : 0.1
dQMin : 0.1
invert : 1
