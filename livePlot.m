function [ data1, cX, cY, cZ, cT] = livePlot(y, cX, cY, cZ, cT, data1)
while length(y) >=14
    if startsWith(y, '1010')
        ident = str2double(y(5:6));
        bin1 = bin2dec(y(7:16));
        switch ident
            case 00
                data1(cT, 1) = bin1;
                cT = cT + 1;
            case 10
                data1(cX, 2) = bin1;
                cX = cX + 1;
            case 01
                data1(cY, 3) = bin1;
                cY = cY + 1;
            case 11
                data1(cZ, 4) = bin1;
                cZ = cZ + 1;
        end
        if length(y)>16
            y = y(17:end);
        else
            y = '';
        end
    else
        y = y(2:end);
    end
end
    

end

