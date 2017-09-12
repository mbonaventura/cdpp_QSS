[top]
components : qssX@QSS1 qssY@QSS1
out : signalOut
link : out@qssY in@qssX
link : out@qssX in@qssY
link : out@qssX signalOut

[qssX]
x0 : 0.5
dQRel : 1e-2
dQMin : 1e-4

[qssY]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4
gain : -1
