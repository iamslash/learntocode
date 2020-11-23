select floor(count(*)/2) into @offset from station;
prepare stmt from 'select round(lat_n,4) from station group by lat_n limit ?, 1';
execute stmt using @offset;
