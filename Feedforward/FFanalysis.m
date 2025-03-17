addpath('Model')
addpath('Measurements')
clear all
clc
%% Load FF (Feed_forward_measurements_for_report.mat)
error_ff0 = measurements_ff0(:,1);
error_ff1 = measurements_ff1(:,1);
error_ff2 = measurements_ff2(:,1);
error_ff3 = measurements_ff3(:,1);
%%
plot(error_ff0(45537:117538))
hold on
plot(error_ff1(45583:117584))
hold on
plot(error_ff2(45408:117409))
hold on
plot(error_ff3(110332:182332))
hold off
legend('No FF', 'Coulomb', 'V', 'A')
% [-0.00038 -0.005 -0.00002]
