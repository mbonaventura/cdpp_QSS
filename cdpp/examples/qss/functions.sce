/// To load and plot timeSeries from cvs files:
/// exec("functions.sce", 0);
/// X = cvs_timeSerie("circularTrajectory/qssx");
/// Y = cvs_timeSerie("circularTrajectory/qssy");
/// scf(); plotTimeSerie(X, ".-red"); plotTimeSerie(Y, ".-blue");


function [timeSerie] = cvs_timeSerie(fileName)
	csv_string  = read_csv(fileName);
	cvs_values = eval(csv_string);
	
	timeSerie.t = cvs_values(1:$, 1)
	timeSerie.value = cvs_values(1:$, 2)
 
endfunction

function [] = plotTimeSerie(timeSerie, mode)
	plot(timeSerie.t, timeSerie.value, mode); 
endfunction