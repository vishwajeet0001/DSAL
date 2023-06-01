class record:
    def __init__(self):
        self.number = None
        self.name = None
        
    
    def get_name(self):
        self.name = str(input("Enter Name :"))
        return self.name
    
    def get_number(self):
        self.number = int(input("Enter Number :"))
        return self.number
    
    