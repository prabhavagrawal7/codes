class Student
    attr_accessor :name, :major, :gpa
    def initialize (name, major, gpa)
    @name = name
    @major = major
    @gpa = gpa
    end 
end
    student1 = Student.new("Jim", "Business", 2.6)
    student2 = Student. new("'Pam", "Art", 3.6)