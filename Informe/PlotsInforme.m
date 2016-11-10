# Inicializador

start = 9;
finish = 18;
for i = start : finish
  rectangles(i - start + 1) = 2^i;
end

# --- START DATA --- #

# Tiempos Inserción Linear Split

lst(1) = 0.090544;
lst(2) = 0.164019;
lst(3) = 0.298953;
lst(4) = 0.521460;
lst(5) = 0.966952;
lst(6) = 2.704462;
lst(7) = 5.425123;
lst(8) = 9.942731;
lst(9) = 19.675351;
lst(10) = 38.226344;

# Tiempos Inserción Greene Split

gst(1) = 0.079349;
gst(2) = 0.134480;
gst(3) = 0.260028;
gst(4) = 0.534319;
gst(5) = 0.963934;
gst(6) = 2.247448;
gst(7) = 4.912580;
gst(8) = 9.818921;
gst(9) = 19.402311;
gst(10) = 38.643265;

# Porcentajes de llenado

percent_fill(1) = 46.1;
percent_fill(2) = 47.6;
percent_fill(3) = 48.8;
percent_fill(4) = 49.5;
percent_fill(5) = 49.7;
percent_fill(6) = 49.8;
percent_fill(7) = 50.0;
percent_fill(8) = 50.1;
percent_fill(9) = 50.1;
percent_fill(10) = 50.2;

# Accesos a disco

disk_access(1) = 102;
disk_access(2) = 204;
disk_access(3) = 408;
disk_access(4) = 818;
disk_access(5) = 1638;
disk_access(6) = 3276;
disk_access(7) = 6552;
disk_access(8) = 13106;
disk_access(9) = 26214;
disk_access(10) = 52428;

# Tiempos Búsqueda Linear Split (seg)

linear_search_time(1) = 0.002877;
linear_search_time(2) = 0.005631;
linear_search_time(3) = 0.011399;
linear_search_time(4) = 0.022630;
linear_search_time(5) = 0.045872;
linear_search_time(6) = 0.116145;
linear_search_time(7) = 0.717755;
linear_search_time(8) = 0.495848;
linear_search_time(9) = 0.832019;
linear_search_time(10) = 2.194899;

# Tiempos Búsqueda Greene Split (seg)

greene_search_time(1) = 0.002891;
greene_search_time(2) = 0.005252;
greene_search_time(3) = 0.010876;
greene_search_time(4) = 0.028296;
greene_search_time(5) = 0.058527;
greene_search_time(6) = 0.093235;
greene_search_time(7) = 0.223559;
greene_search_time(8) = 0.465250;
greene_search_time(9) = 1.389346;
greene_search_time(10) = 2.282709;

# --- END DATA --- #

# Plot para Inserción

figure(1);
hold on;
plot(rectangles, lst, "r");
plot(rectangles, gst, "b");
legend("Linear Split", "Greene Split");
grid on;
xlabel ("Numero de Rectangulos");
ylabel ("Tiempo (segs)");
title ("Linear y Greene Split - Numero de Rectangulos vs Tiempo de insercion");
hold off;

# Plot para espacio y % de llenado

figure(2);
hold on;
plot(rectangles, percent_fill, "b");
grid on;
legend("% llenado");
xlabel ("Numero de Rectangulos");
ylabel ("Porcentaje de llenado del nodo");
title ("Numero de Rectangulos vs % de llenado de nodos");
hold off;

# Plot para búsqueda

figure(3);
hold on;
plot(rectangles, linear_search_time, "r");
plot(rectangles, greene_search_time, "b");
legend("Linear Split", "Greene Split");
grid on;
xlabel ("Numero de Rectangulos");
ylabel ("Tiempo de busqueda (segs)");
title ("Linear y Greene Split - Numero de Rectangulos vs Tiempo de busqueda");
hold off;

# Plot para accesos a disco

figure(4);
hold on;
plot(rectangles, disk_access, "r");
legend("Accesos a disco");
grid on;
xlabel ("Numero de Rectangulos");
ylabel ("Accesos a disco");
title ("Numero de Rectangulos vs Accesos a disco");
hold off;
