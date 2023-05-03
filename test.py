import asyncio

async def main(): 
    task = asyncio.create_task(other_function())
    print("A")
    await asyncio.sleep(1)
    print("B")
    # await task 
    return_value = await task
    print(f"return value = {return_value}")


async def other_function(): 
    print("1")
    await asyncio.sleep(2)
    print("2")
    return 10



print(asyncio.run(main()))