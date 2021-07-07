from detecto import core, utils, visualize

dataset = core.Dataset('images/')
model = core.Model(['crop'])

model.fit(dataset)

model.save('model_weights.pth')
