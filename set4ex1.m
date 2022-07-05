clear; clc; clf;
a=load("net1k1000.txt");
figure(1)
h=histogram(a)
title('Ιστόγραμμα κατανομής μέσων συνδέσεων k - 1000 κόμβοι')
xlabel('Μέσες τιμές k μετά από 1000 runs')
ylabel('Πλήθος εμφάνισης κάθε σύνδεσης')
fitdist(a,'Poisson')
%% Briskw thn <k>
counts=h.Values/length(a);
c=(h.BinEdges+h.BinWidth/2);
centers=c(1:end-1);
p=0.0;
for i=1:length(counts)
       if p<counts(i)
           p=counts(i);
           imax=i;
       end
end
k=centers(imax)
figure(2)
plot(centers,counts)
title('Συνάρτηση Πυκνότητας Πιθανότητας - 1000 κόμβοι')
xlabel('Μέσες τιμές των k μετά από 1000 runs')
ylabel('P(k)')
% txt=['<k>=',num2str(k)];
text(k,0.05,['<k>=',num2str(k)],'HorizontalAlignment','center')

%% Apo distribution
figure(3)
b=load("net1d1000.txt");
plot(b(:,1),b(:,2)/length(b))
title('Συνάρτηση Πυκνότητας Πιθανότητας - 1000 κόμβοι')
xlabel('Μέσες τιμές των k μετά από 1000 runs')
ylabel('P(k)')
axis([165 168 0 0.000000045])