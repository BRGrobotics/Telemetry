clear
clc
close all

delete(instrfind({'Port'},{'/dev/cu.usbmodem1461'}));
s = serial('/dev/cu.usbmodem1461');
set(s,'BaudRate',115200,'Parity','even')
fopen(s);

cX = 1;
cY = 1;
cZ = 1;
cT = 1;
data1 = [];

figure('Name', 'Live Telemetry');
figure('units','normalized','outerposition',[0 0 1 1])
title('AAAAAAAMTECH Live Telemtry');
xlabel('Time');
ylabel('Reading');

range = 1:10;


x = 1000;
while x > 0
    y = fscanf(s, '%s');
    fprintf('%0.0f', y);
    
    if length(y)>50
        fclose(s);
        [data1, cX, cY, cZ, cT] = livePlot(y, cX, cY, cZ, cT, data1);
        y = '';
        if (cX >=11) && (cY >=11) && (cZ >=11) && (cT >=11)
            dataX = data1(cX-10:cX-1, 2);
            dataY = data1(cY-10:cY-1, 3);
            dataZ = data1(cZ-10:cZ-1, 4);
            dataT = data1(cT-10:cT-1, 1);
            clf;
            grid;
            plot(range, dataT, '-r', 'LineWidth', 1);
            hold on;
            plot(range, dataX, '-b','LineWidth', 1);
            plot(range, dataY, '-g','LineWidth', 1);
            plot(range, dataZ, '-k','LineWidth', 1);
            
        end
        fopen(s);
    end
    pause(.7);
end