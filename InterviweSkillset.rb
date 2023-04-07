#minimal skillset foir ruby

class Identity
	attr_accessor :id

	def initialize(id, hash, opt)
		@id = id
		@hash = hash
		@opt = opt
	end

	def to_s
		"id: #@id\nhash: #@hash\nopt: #@opt"
	end
	
end

class Obj
	attr_accessor :head
	def initialize(h)
		@head = h
		@val = []
		@id
	end

	def sortval()
		@val = @val.sort()
	end

	def add(v)
		@val.push(v)
	end

	def setId=(id)
		@id = id
	end

	def display()
		puts "---------------------"
		puts @head
		puts @id.to_s
		
		@val.each do |v|
			puts v
		end
	end
end

s = ["Regis", "Laurent", "Andre", "Joe", "Louis"]
tobj = []

srand 1239

x=0
s.each do |s|
	o = Obj.new(s)
	(1..10).each do |i|
		o.add(rand(1000000))
	end
	o.sortval()

	hash = rand(1000000000)
	o.setId=Identity.new(x, hash, "")
	tobj.push(o)
	x+=1

end

tobj.each do |o|
	o.display
end

tobj = tobj.sort{|a, b| a.head <=> b.head}

puts "*******************************************************"
tobj.each do |o|
	o.display
end