clear;

fileID = fopen('dane.txt');

data = reshape(textread('dane.txt','%d','delimiter','\n'),129,52152)';

output_vector = zeros(52152,26);

for i = 1:52152
    output_vector(i,data(i,129)) = 1;
end


training_set = data(1:40000,1:128)';
output_training = output_vector(1:40000,:)';
check_set = data(40001:52152,1:128)';
output_check = output_vector(40001:52152,:)';

clear output_vector data i fileID;