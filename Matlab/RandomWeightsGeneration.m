function [ output_args ] = RandomWeightsGeneration( neuron_count )
%RANDOMWEIGHTSGENERATION Summary of this function goes here
%   Detailed explanation goes here
layer_count = 3;
for i = 2:layer_count
    for j = 1:neuron_count(i)
       for k = 1:neuron_count(i-1)
           output_args(i,j,k) = rand();
           if (output_args(i,j,k) == 0)
               output_args(i,j,k) = 0.01492;
           end
       end
    end
end

assignin('base','layer_count',layer_count);
assignin('base','weights',output_args);

end

