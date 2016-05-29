function [ output_args ] = Process(neuron_count)
%PROCESS Summary of this function goes here
%   Detailed explanation goes here

% for(i=1;i<LW;i++)
%  for(j=0;j<n[i];j++)
%  {
%   I[i][j] = 0.0;
%   for(k=0;k<=n[i-1];k++)
%    I[i][j] += O[i-1][k] * W[i][j][k];
%   O[i][j] = 1.0 / (1.0 + exp(beta*(-I[i][j])));
%  }

layer_count = 3;

O = zeros(layer_count,128);
O = zeros(layer_count,128);

for i=2:layer_count
   for j = 1: neuron_count(i)
       I(i,j) = 0.0;
       for k = 1: neuron_count(i-1)
           I(i,j) = I(i,j) + O(i-1,k)*weights(i,j,k);
       end
       
       O(i,j) = Sigmoid(I(i,j));
   end
end

assignin('base','I',I);
assignin('base','O',O);

end

