%% Pi
p = raspi('10.55.0.1','pi','sperte123')
%% Path
addpath('Model')
%% Measurements C3
T_measure = 60;
measurements_reference_c3 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedback",1);
%%
error_3 = measurements_reference_c3(:,1);
acc_3 = measurements_reference_c3(:,2);
velocity_3 = measurements_reference_c3(:,3);
find(velocity_3 == 0)
%% Computing
sample_i_3 = 109946;
sample_f_3 = 157089;
error_period_3 = error_3(sample_i_3:sample_f_3);
acc_period_3 = acc_3(sample_i_3:sample_f_3);
velocity_period_3 = velocity_3(sample_i_3:sample_f_3);
constant_velocity_stroke_3 = acc_period_3==0 & velocity_period_3 ~= 0;

error_constant_velocity_3 = error_period_3(constant_velocity_stroke_3);

plot(error_constant_velocity_3)
max_error = norm(error_constant_velocity_3, 'Inf')
rms_error = rms(error_constant_velocity_3)

%%
[Error_PSD_3, f_PSD_3] = pwelch(error_constant_velocity_3, hann(8000),4000,8000,4000);
dataBode(Error_PSD_3,f_PSD_3)
%% Measurements C4
T_measure = 60;
measurements_reference_c4 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedback",1);
%%
error_4 = measurements_reference_c4(:,1);
acc_4 = measurements_reference_c4(:,2);
velocity_4 = measurements_reference_c4(:,3);
%%
plot(acc_4)
%% Computing
sample_i_4 = 112200;
sample_f_4 = 157654;
error_period_4 = error_4(sample_i_4:sample_f_4);
acc_period_4 = acc_4(sample_i_4:sample_f_4);
velocity_period_4 = velocity_4(sample_i_3:sample_f_3);
constant_velocity_stroke_4 = acc_period_4==0 & velocity_period_4 ~= 0;

error_constant_velocity_4 = error_period_4(constant_velocity_stroke_4);

plot(error_constant_velocity_4)
max_error = norm(error_constant_velocity_4, 'Inf')
rms_error = rms(error_constant_velocity_4)

%%
[Error_PSD_4, f_PSD_4] = pwelch(error_constant_velocity_4, hann(8000),4000,8000,4000);
dataBode(Error_PSD_4,f_PSD_4)
%% Measurements C5
T_measure = 60;
measurements_reference_c5 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedback",1);
%%
error_5 = measurements_reference_c5(:,1);
acc_5 = measurements_reference_c5(:,2);
velocity_5 = measurements_reference_c5(:,3);

plot(velocity_5)
find(velocity_5==0)
%% Computing
sample_i_5 = 126960;
sample_f_5 = 174103;
error_period_5 = error_5(sample_i_5:sample_f_5);
acc_period_5 = acc_5(sample_i_5:sample_f_5);
velocity_period_5 = velocity_5(sample_i_5:sample_f_5);
constant_velocity_stroke_5 = acc_period_5==0 & velocity_period_5 ~= 0;

error_constant_velocity_5 = error_period_5(constant_velocity_stroke_5);

plot(error_constant_velocity_5)
max_error = norm(error_constant_velocity_5, 'Inf')
rms_error = rms(error_constant_velocity_5)

%%
[Error_PSD_5, f_PSD_5] = pwelch(error_constant_velocity_5, hann(8000),4000,8000,4000);
semilogy(f_PSD_3(1:200), Error_PSD_3(1:200))
hold on
semilogy(f_PSD_4(1:200), Error_PSD_4(1:200))
hold on
semilogy(f_PSD_5(1:200), Error_PSD_5(1:200))
hold off
legend('C3','C4','C5')
% Error at resonance at 1e-7
% Error at rotational at 3e-7

%%
figure
% plot(error_constant_velocity_3);
% hold on
plot(error_constant_velocity_4);
hold on
plot(error_constant_velocity_5);
hold off
legend('C3','C5')

%% DataBode
function dataBode(H,f)
    figure;
    subplot(2,1,1);
    semilogx(f,db(H))
    ylabel("|H| (db)")
    subplot(2,1,2);
    semilogx(f,angle(H)/pi*180)
    ylabel("\angle H (\circ)")
    xlabel('f (Hz)')
end